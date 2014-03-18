#include "JobListWidget.h"
#include "JobQueueModel.h"
#include "JobItem.h"
#include "JobListViewDelegate.h"
#include "styledbar.h"
#include <QPushButton>
#include <QListView>
#include <QVBoxLayout>
#include <QDebug>


JobListWidget::JobListWidget(QWidget *parent)
    : QWidget(parent)
    , m_jobQueueModel(0)
    , m_listViewDelegate(new JobListViewDelegate(this))
    , m_listView(new QListView(this))
    , m_submitButton(new QPushButton("Submit"))
    , m_runButton(new QPushButton("Run"))
    , m_saveButton(new QPushButton("Save"))
{
//    setMinimumSize(128, 128);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_listView->setDragEnabled(true);
    m_listView->setAcceptDrops(true);
    m_listView->setDefaultDropAction(Qt::MoveAction);
    m_listView->setItemDelegate(m_listViewDelegate);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    Manhattan::StyledBar *bar = new Manhattan::StyledBar;
    mainLayout->addWidget(bar);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(m_submitButton);
    buttonsLayout->addWidget(m_runButton);
    buttonsLayout->addWidget(m_saveButton);
    buttonsLayout->addStretch(1);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->setMargin(10);
    vlayout->setSpacing(10);

    vlayout->addLayout(buttonsLayout);
    vlayout->addWidget(m_listView);

    mainLayout->addLayout(vlayout);

    setLayout(mainLayout);

    connect(m_saveButton, SIGNAL(clicked()), this, SLOT(save()));
    connect(m_submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(m_runButton, SIGNAL(clicked()), this, SLOT(run()));
}


void JobListWidget::setModel(JobQueueModel *model)
{
    Q_ASSERT(model);
    if(model != m_jobQueueModel) {
        m_jobQueueModel = model;
        m_listView->setModel(model);

        connect(m_listView->selectionModel(),
            SIGNAL( selectionChanged(const QItemSelection&, const QItemSelection&) ),
            m_jobQueueModel,
            SLOT( onSelectionChanged(const QItemSelection&, const QItemSelection&) )
            );

        connect(m_listViewDelegate, SIGNAL(cancelButtonClicked(QModelIndex)),
        m_jobQueueModel, SLOT(onCancelJob(QModelIndex)));

    }
}


void JobListWidget::save()
{
    Q_ASSERT(m_jobQueueModel);
    qDebug() << "JobListWidget::save() -> ";
    m_jobQueueModel->save("tmp2.xml");

}


void JobListWidget::submit()
{
    Q_ASSERT(m_jobQueueModel);
    qDebug() << "JobListWidget::submit() -> ";
//    m_jobQueueModel->addJob(new JobItem(QString("job")+QString::number(i++)));

    m_jobQueueModel->addJob(0);

}


void JobListWidget::run()
{
    Q_ASSERT(m_jobQueueModel);
    qDebug() << "JobListWidget::run()";

    QModelIndexList indexList = m_listView->selectionModel()->selectedIndexes();
    qDebug() <<indexList;

    if(!indexList.empty()) {
        m_jobQueueModel->runInThread(indexList.front());
//        JobItem *job = m_jobQueueModel->getJobQueueItemForIndex(indexList.front());
//        qDebug() << "JobListWidget::run()" << job->getName();
////        job->run();
//        m_jobQueueModel->runInThread(job);
    }
}
