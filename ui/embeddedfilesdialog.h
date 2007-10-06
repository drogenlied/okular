/***************************************************************************
 *   Copyright (C) 2006 by Albert Astals Cid <aacid@kde.org>               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef _EMBEDDEDFILESDIALOG_H_
#define _EMBEDDEDFILESDIALOG_H_

#include <QtCore/QHash>

#include <QtCore/QHash>

#include <kdialog.h>
#include <QtCore/QHash>

class QTreeWidget;
class QTreeWidgetItem;

namespace Okular {
class Document;
class EmbeddedFile;
}

class EmbeddedFilesDialog : public KDialog
{
Q_OBJECT
	public:
		EmbeddedFilesDialog(QWidget *parent, const Okular::Document *document);
	
	private slots:
		void saveFile();
		void attachViewContextMenu( const QPoint& pos );
	
	private:
		void saveFile( Okular::EmbeddedFile* );

		QTreeWidget *m_tw;
		QHash<QTreeWidgetItem *, Okular::EmbeddedFile*> m_files;
};

#endif
