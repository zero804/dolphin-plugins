/***************************************************************************
 *   Copyright (C) 2011 by Vishesh Yadav <vishesh3y@gmail.com>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#include "generalsettings.h"
#include "hgconfig.h"

#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtCore/QString>
#include <klocale.h>

HgGeneralConfig::HgGeneralConfig(QWidget *parent):
    QWidget(parent)
{
    setupUI();
    loadConfig();
}

void HgGeneralConfig::setupUI()
{
    m_userEdit = new KLineEdit;
    m_editorEdit = new KLineEdit;
    m_mergeEdit = new KLineEdit;
    m_verboseCheck = new QCheckBox(i18nc("@label:checkbox", "Verbose Output"));
    
    QLabel *userLabel = new QLabel(i18nc("@label", "Username"));
    QLabel *editorLabel = new QLabel(i18nc("@label", "Default Editor"));
    QLabel *mergeLabel = new QLabel(i18nc("@label", "Default Merge Tool"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(userLabel, 0, 0);
    mainLayout->addWidget(m_userEdit, 0, 1);
    mainLayout->addWidget(editorLabel, 1, 0);
    mainLayout->addWidget(m_editorEdit, 1, 1);
    mainLayout->addWidget(mergeLabel, 2, 0);
    mainLayout->addWidget(m_mergeEdit, 2, 1);
    mainLayout->addWidget(m_verboseCheck, 3, 0, 2, 0);

    setLayout(mainLayout);
}

void HgGeneralConfig::loadConfig()
{
    HgConfig hgc(HgConfig::GlobalConfig);

    m_userEdit->setText(hgc.username());
    m_editorEdit->setText(hgc.editor());
    m_mergeEdit->setText(hgc.merge());

    QString verbose = hgc.property(QLatin1String("ui"), QLatin1String("verobose"));
    if (verbose.isEmpty() || verbose == "False") {
        m_verboseCheck->setChecked(false);
    }
    else if (verbose == "True") {
        m_verboseCheck->setChecked(true);
    }
}

void HgGeneralConfig::saveConfig()
{
    HgConfig hgc(HgConfig::GlobalConfig);
    hgc.setUsername(m_userEdit->text());
    hgc.setEditor(m_editorEdit->text());
    hgc.setMerge(m_mergeEdit->text());

    if (m_verboseCheck->checkState() == Qt::Checked) {
        hgc.setProperty(QLatin1String("ui"), QLatin1String("verbose"),
                QLatin1String("True"));
    }
    else {
        hgc.setProperty(QLatin1String("ui"), QLatin1String("verbose"),
                QLatin1String("False"));
    }
}

#include "generalsettings.moc"

