#include "NodeEditor.h"
#include "NodeEditorPort.h"
#include "NodeEditorConnection.h"
#include <QGraphicsScene>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>


NodeEditor::NodeEditor(QObject *parent) :
    QObject(parent)
{
	conn = 0;
}


void NodeEditor::install(QGraphicsScene *s)
{
	s->installEventFilter(this);
	scene = s;
}


QGraphicsItem* NodeEditor::itemAt(const QPointF &pos)
{
	QList<QGraphicsItem*> items = scene->items(QRectF(pos - QPointF(1,1), QSize(3,3)));

	foreach(QGraphicsItem *item, items)
		if (item->type() > QGraphicsItem::UserType)
			return item;

	return 0;
}


bool NodeEditor::eventFilter(QObject *o, QEvent *e)
{
    QGraphicsSceneMouseEvent *me = (QGraphicsSceneMouseEvent*) e;

    switch ((int) e->type())
    {
    case QEvent::GraphicsSceneMousePress:
    {
        switch ((int) me->button())
        {
        case Qt::LeftButton:
        {
            QGraphicsItem *item = itemAt(me->scenePos());
            if (item && item->type() == NodeEditorPort::Type)
            {
                conn = new NodeEditorConnection(0, scene);
                conn->setPort1((NodeEditorPort*) item);
                conn->setPos1(item->scenePos());
                conn->setPos2(me->scenePos());
                conn->updatePath();

                return true;
            }
            break;
        }
        }
    }
    case QEvent::GraphicsSceneMouseMove:
    {
        if (conn)
        {
            conn->setPos2(me->scenePos());
            conn->updatePath();
            return true;
        }
        break;
    }
    case QEvent::GraphicsSceneMouseRelease:
    {
        if (conn && me->button() == Qt::LeftButton)
        {
            QGraphicsItem *item = itemAt(me->scenePos());
            if (item && item->type() == NodeEditorPort::Type)
            {
                NodeEditorPort *port1 = conn->port1();
                NodeEditorPort *port2 = (NodeEditorPort*) item;

                if (port1->parentItem() != port2->parentItem()
                        && port1->isOutput() != port2->isOutput()
                        && !port1->isConnected(port2)
                        && port1->getPortType() == port2->getPortType()
                        )
                {
                    conn->setPos2(port2->scenePos());
                    conn->setPort2(port2);
                    conn->updatePath();
                    conn = 0;
                    return true;
                }
            }

            delete conn;
            conn = 0;
            return true;
        }
        break;
    }
    }
    return QObject::eventFilter(o, e);
}
