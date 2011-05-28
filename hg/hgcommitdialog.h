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

#ifndef HGCOMMITDIALOG_H
#define HGRENAMEDIALOG_H

#include <kdialog.h>
#include <klineedit.h>
#include <kfileitem.h>
#include <QtCore/QString>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QLineEdit>
#include <kmessagebox.h>
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser>
#include <klistwidget.h>
#include <kpushbutton.h>

class HgCommitDialog : public KDialog
{
    Q_OBJECT

public:
    HgCommitDialog(QWidget* parent = 0);

private slots:
    void slotButtonClicked(int button);

private:
    QString m_hgBaseDir;
    
    KListWidget *m_fileList;
    QTextEdit *m_commitMessage;
    KLineEdit *m_fileFilter;
    KPushButton *m_optionsButton;
    
    KTextEditor::View *m_fileDiffView;
    KTextEditor::Document *m_fileDiffDoc;
};

#endif // HGCOMMITDIALOG_H

