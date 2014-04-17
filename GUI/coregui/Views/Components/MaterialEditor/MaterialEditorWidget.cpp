#include "MaterialEditorWidget.h"
#include "MaterialPropertyBrowser.h"
#include "MaterialModel.h"
#include <QStyle>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QAction>
#include <QDebug>


int MaterialEditorWidget::m_IndexOfUnnamed = 0;

MaterialEditorWidget::MaterialEditorWidget(MaterialModel *model, QWidget *parent)
    : QWidget(parent)
    , m_materialModel(model)
    , m_propertyBrowser(new MaterialPropertyBrowser(model, this))
    , m_statusBar(0)
    , m_toolBar(0)
{
    setWindowTitle("Material Editor");
    setMinimumSize(128, 128);
    resize(512, 256);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_toolBar = new QToolBar;
    m_toolBar->setFixedHeight(28);
    m_toolBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    const int size = style()->pixelMetric(QStyle::PM_SmallIconSize);
    m_toolBar->setIconSize(QSize(size, size));
    m_toolBar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    m_statusBar = new QStatusBar;
    //connect(m_tableModel, SIGNAL(SetDataMessage(QString)), this, SLOT(showMessage(QString)));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_toolBar);
    layout->addWidget(m_propertyBrowser);

    //QPushButton *closeButton = new QPushButton(tr("Close"));
    //connect(closeButton, SIGNAL(clicked()), this, SLOT(closeButtonClicked()));
    //QHBoxLayout *buttonsLayout = new QHBoxLayout;
    //buttonsLayout->addStretch(1);
    //buttonsLayout->addWidget(closeButton);
    //buttonsLayout->setMargin(0);
    //buttonsLayout->setSpacing(0);
    //layout->addLayout(buttonsLayout);

    layout->addWidget(m_statusBar);

    setLayout(layout);

    setupActions();
}


void MaterialEditorWidget::setModel(MaterialModel *model)
{
    Q_ASSERT(model);
    if(model != m_materialModel) {
        m_materialModel = model;
        m_propertyBrowser->setModel(model);
    }

}


void MaterialEditorWidget::showMessage(const QString &message)
{
    m_statusBar->showMessage(message, 4000);
}


void MaterialEditorWidget::setupActions()
{
    QAction *addMaterialAction = new QAction(QIcon(":/SampleDesigner/images/card--plus.png"), tr("Add material"), this);
    connect(addMaterialAction, SIGNAL(triggered()), this, SLOT(addMaterial()));
    m_toolBar->addAction(addMaterialAction);

    QAction *removeMaterialAction = new QAction(QIcon(":/SampleDesigner/images/card--minus.png"), tr("Remove selected material"), this);
    connect(removeMaterialAction, SIGNAL(triggered()), this, SLOT(removeMaterial()));
    m_toolBar->addAction(removeMaterialAction);
}


void MaterialEditorWidget::addMaterial()
{
    qDebug() << "MaterialEditorWidget::addMaterial() -> ";
    QString name = QString("unnamed%1").arg(m_IndexOfUnnamed);
    m_materialModel->addMaterial(name, MaterialItem::HomogeneousMaterial);
    m_IndexOfUnnamed++;
}


void MaterialEditorWidget::removeMaterial()
{
    qDebug() << "MaterialEditorWidget::removeMaterial() -> ";
    MaterialItem *material = m_propertyBrowser->getSelectedMaterial();
    if(material)
        m_materialModel->removeMaterial(material);
}
