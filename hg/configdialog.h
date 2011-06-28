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

#ifndef HGCONFIGDILAOG_H
#define HGCONFIGDILAOG_H

#include "config-widgets/generalsettings.h"

#include <QtGui/QGroupBox>
#include <klineedit.h>
#include <kpagedialog.h>

class HgConfigDialog : public KPageDialog
{
    Q_OBJECT

public:
    HgConfigDialog(QWidget *parent = 0);

private:
    void done(int r);

    // user interface
    void setupUI();

private slots:
    void saveSettings();

private:
    HgGeneralConfig *m_generalConfig;

};

#endif // HGCONFIGDILAOG_H

