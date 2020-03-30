// #include <string>
// #include <vector>
// C++ includes
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stdlib.h>
// Qt includes
#include <QFile>
#include <QString>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
// app include
#include "QtGuiAppBoduc.h"

QtGuiAppBoduc::QtGuiAppBoduc(QWidget *parent)
	: QMainWindow(parent)
{
	// just testing access to the global variable qApp
	// since we are now inherit from QApplication
	auto w_checkVersion = qApp->applicationVersion();
	QDesktopWidget* w_desktop = qApp->desktop();

	ui.setupUi(this);

	// just a test
	//ui.m_loadPushButton->setEnabled(false);
}

void QtGuiAppBoduc::processCmdFiles()
{
	throw("Not implemented yet");
}

void QtGuiAppBoduc::loadCmdFiles()
{
	// let user select files ()
	selectFiles();

	if (m_filesName.size() > 1) // user selected more than one files
	{
		std::list<std::string> w_listFilesName;
		QStringList::const_iterator w_begList = m_filesName.constBegin();
		QStringList::const_iterator w_endList = m_filesName.constEnd();
		while (w_begList != w_endList)
		{
			std::cout << "Loading the following files: " << w_begList->toStdString() << std::endl;
			w_listFilesName.push_back(w_begList->toStdString());
			++w_begList;
		}

		// loop on each files in the list (fill vector map for processing multiple files in one step)
		//readFiles( w_listFilesName, std::string("Signature"));

		//			m_console->append("Finished loading files");
	}
	else // only one file
	{
		// actually what we do here, we split bill into separate cmd 
		// (case where we have multiple command in the same file)
		// not sure the behavior for single files (command are already 
		// in single file) and we process each file one after the other.  
		//m_bdApp.readFile( m_fileName.toStdString(), std::string("Signature"));
		QFile w_fileName(m_filesName.first());
		readFile( w_fileName, QString("Signature")); // first in the list (only one) 

		// i am not sure what we do here
	//	size_t w_nbCmdCheck = m_bdApp.nbOfCmd();
	}

	//		m_console->append("Ready to  process these files");

// 	if (!m_procButton->isEnabled())
// 	{
// 		m_procButton->setEnabled(true);
// 	}
// 	if (m_analyzeLoadButton->isEnabled())
// 	{
// 		m_analyzeLoadButton->setEnabled(false);
// 	}
// }
}

// NOT COMPLETD *******************************
// at the moment we support 10 unit just do a check on each of them
// call when user select to save selection
//TODO: deprecated
void QtGuiAppBoduc::updateProgress()
{
// 	if (m_currUnityON.compare(m_listUniteAvailable.at(0)) == 0) // identical
// 	{
// 		double w_val2Show = m_progressBar[0]->value() + std::get<2>(m_bdBonFields);
// 		m_progressBar[0]->setValue(w_val2Show);
// 	}
// 	else if (m_currUnityON.compare(m_listUniteAvailable.at(1)) == 0)
// 	{
// 		double w_val2Show = m_progressBar[1]->value() + std::get<2>(m_bdBonFields);
// 		m_progressBar[1]->setValue(w_val2Show);
// 	}
// 	else if (m_currUnityON.compare(m_listUniteAvailable.at(2)) == 0)
// 	{
// 		double w_val2Show = m_progressBar[2]->value() + std::get<2>(m_bdBonFields);
// 		m_progressBar[2]->setValue(w_val2Show);
// 	}
// 	else if (m_currUnityON.compare(m_listUniteAvailable.at(3)) == 0)
// 	{
// 		double w_val2Show = m_progressBar[3]->value() + std::get<2>(m_bdBonFields);
// 		m_progressBar[3]->setValue(w_val2Show);
// 	}
// 	else if (m_currUnityON.compare(m_listUniteAvailable.at(4)) == 0)
// 	{
// 		double w_val2Show = m_progressBar[4]->value() + std::get<2>(m_bdBonFields);
// 		m_progressBar[4]->setValue(w_val2Show);
// 	}
}

void QtGuiAppBoduc::setMode()
{
// 	if (m_capacityLoad == eCapacityMode::normal)
// 	{
// 		m_cptySelectBtn->setText(QString("Degel Load"));
// 		m_capacityLoad = eCapacityMode::degel;
// 	}
// 	else
// 	{
// 		m_cptySelectBtn->setText(QString("Normal Load"));
// 		m_capacityLoad = eCapacityMode::normal;
// 	}
}

void QtGuiAppBoduc::currentUniteON()
{
	// user change unity selection
// 	int w_uniteCurrent = m_listUnite->currentIndex(); // user choice
// 	m_currUnityON = m_listUnite->itemText(w_uniteCurrent);
}

// Design Note (March 19)
//  Can be done by using a while loop. While !=0 continue
//  Once found, m_progressBar[i] whatever you want to do.
//  Extract in a separate method value update and msg box.
//  
bool QtGuiAppBoduc::updateUnitProgress(const float aVal2Update)
{
	// loop over layout item?? 
	// Progress bar are part of the VBoxLayout or HBoxLayout 

// 	bool ret = true;
// 	if (m_currUnityON.compare(m_listUniteAvailable.at(0)) == 0) // identical
// 	{
// 		double w_val2Show = m_progressBar[0]->value() + aVal2Update;
// 		if (w_val2Show > m_progressBar[0]->maximum())
// 		{
// 			QMessageBox msgBox;
// 			msgBox.setWindowTitle("Exceed Load");
// 			msgBox.setText("Maximum load is " + QString(std::to_string(m_progressBar[0]->maximum()).c_str()));
// 			msgBox.exec();
// 			ret = false;
// 		}
// 		m_progressBar[0]->setValue(w_val2Show);
// 	}

	return false; //debugging purpose
}

// called when "open" button clicked
// by default all files for testing are located in a folder named "DataToTest"
void QtGuiAppBoduc::selectFiles()
{
	// setting default directory to start with 
	// i need to check, which is the root directory of the VS15 project
	QString w_defaultDir = QDir::currentPath();

	// Create a log file
	std::cout << "Current of the opening file is : " << w_defaultDir.toStdString() << std::endl;

	// multiple file selection support
	// now opening file to be processed (name of the file returned)
	m_filesName = QFileDialog::getOpenFileNames(this, tr("Open File"),
		w_defaultDir,
		tr("Text (*.txt *.csv *.pdf)"));

	// Handle case where user click cancel
	if( m_filesName.isEmpty()) { // no selection
		// functionA
	}

	bool w_checkFileExt = std::all_of(m_filesName.constBegin(), m_filesName.constEnd(),
		[](const QString& aFileName)
	{
		QFileInfo w_file2Look(aFileName);
		QString w_fExt = w_file2Look.completeSuffix();
		return (w_fExt.compare("pdf") == 0); // equal (set to txt for debugging purpose, but it should be pdf)
	});

// 	if (w_checkFileExt)
// 	{
// 		m_bdApp.setFileType(bdAPI::BoDucApp::eFileType::pdf);
// 		//convertPdf2Txt();
// 	}
// 	else
// 	{
// 		m_bdApp.setFileType(bdAPI::BoDucApp::eFileType::csv);
// 	}
// 
// 	// number of files selected by user
// 	m_fileLoaded = m_filesName.size();
		
	//	m_bdApp.setNbSelectedFiles(m_fileLoaded);

	// ???
// 	if (m_filesName.size() == 1)
// 	{
// 		if (m_filesName.size() == 1)
// 			m_fileName = m_filesName.front(); // only file in the list
// 
// 		qWarning("Could not open file for reading");
// 	}

	// activate button, can now start parsing the .csv file
// 	if (!m_analyzeLoadButton->isEnabled())
// 	{
// 		m_analyzeLoadButton->setEnabled(true);
// 	}
// 
// 	m_openButton->setEnabled(false);
	//		m_console->append(QString("Click load button to read file ..."));
}

void QtGuiAppBoduc::readFile( const QFile& aFileAnPath, const QString& aSplitBill)
{
	using namespace std;

	// lambda (anonymous) function declaration
	auto checkTransportName = [this](const QString& aStr2Look) -> bool
	{
		// Transporteur name validation (BoDuc)
		return m_listValidTransporteur.contains(aStr2Look);
	};

	// make sure that container are reset to zero size
//	resetContainerData(aFileAnPath);

	//std::vector<std::string> w_vecStr;
	//w_vecStr.reserve(50); // reserve some memory
	// Design Note 
	//   all tyes shall QT types. Here we use std::ifstream, but we sould use 
	//   QTextStream
	//
	QStringList w_cmdText;
	QFile w_file(m_fileName); // this is a name of a file text1.txt sent from main method
	if( !w_file.open( QIODevice::ReadOnly | QIODevice::Text))
	{
		// shall return error message 
		QMessageBox msgBox;
		QFileInfo w_filExtract(aFileAnPath);
		const QString w_fileName = w_filExtract.fileName();
		QString w_strMsg = QString("The document ") + w_fileName + QString(" could not be opened.");
		msgBox.setText(w_strMsg);
		msgBox.setInformativeText("We try to fix it, do you want to proceed?");
		msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
		msgBox.setIcon(QMessageBox::Warning);
		int ret = msgBox.exec();
	}
	else {
		QTextStream w_streamFile(&w_file);
		QString line = w_streamFile.readLine();
		if( !line.contains("Ordered on"))
		{
			w_cmdText.push_back(line);
		}
		while (!line.isNull())
		{
			line = w_streamFile.readLine();
			w_cmdText.push_back(line);

			// NOTE we assume that we are at the last line of the command
			// then we check if the carrier string name is part of the whole 
			// command (if so, add it to the map otherwise skip it)
			// IMPORTANT this algorithm assume that we are at the end or the 
			// last line (split into separate command is based on this assumption)
			// if not the case then it won't work!!
			if( line.contains(aSplitBill))
			{
				// check for carrier name some are different and don't need to be treated
				// Francois mentioned that field can be blank, need to be careful
				if( any_of( w_cmdText.cbegin(), w_cmdText.cend(), checkTransportName))
				{
					//m_mapintVec.insert(make_pair(i++, w_vecStr));
					m_vecCmdText.push_back( std::move(w_cmdText));
					//w_cmdText.clear();  really need it
				}
				else
				{
					QMessageBox w_msgBname;
					QFileInfo w_filExtract(aFileAnPath);
					const QString w_fileName = w_filExtract.fileName();
					QString w_strMsg = QString("Not a valid transporteur name in ") + w_fileName;
					w_msgBname.setText(w_strMsg);
					w_msgBname.setIcon(QMessageBox::Warning);
					w_msgBname.exec();
					// ready for the next iteration
					w_cmdText.clear();
				}
			}
		//}for-loop
	//}if
		}//while-loop
	}//else
}

void QtGuiAppBoduc::resetContainerData( const QFile& aFileAnPath)
{
	if (!m_fileName.size()!=0)
	{
		m_fileName.clear();
	}

	// just testing
	QString w_filePath=aFileAnPath.fileName();
	QByteArray w_byteRepStr(w_filePath.toStdString().c_str());
	QString utf8FileName = QString::fromUtf8(w_byteRepStr);

	// check for accent in file name, if so fix it
// 	if( std::find_if(aFileAnPath.cbegin(), aFileAnPath.cend(), charPredicate) != aFileAnPath.cend())
// 	{
// 		// we have special character, need to fix name without accent
// 		std::wstring w_utf8FileName = BoDucUtility::FromUtf8ToUtf16(aFileAnPath);
// 		m_fileName.assign(w_utf8FileName.cbegin(), w_utf8FileName.cend());
// 	}
// 	else
// 	{
// 		// csv file that we are processing
// 		m_fileName.assign(aFileAnPath.cbegin(), aFileAnPath.cend());
// 	}

	// declare vector to store our string from csv document 
	//vecofstr w_vecStr;
	//w_vecStr.reserve(50); // reserve enough space for storing each line ??

	// first time we go through we fill the map
  // but next we go in (didn't close the app),
	// we must empty the container ... i do not understand
	if( !m_vecCmdText.empty())
	{
		// clear all content
		m_vecCmdText.clear();

		// sanity check
// 		if (m_mapintVec.size() != 0)
// 		{
// 			std::cerr << "Map of lines not empty\n";
// 		}
	}
}

// Reading command file and fill the vector of string for each command.
// Added to a map to it is used 
void QtGuiAppBoduc::readFiles( const QStringList & aFilesNameWithPath, const std::string & aSplitBill)
{
	// Design Note:
	//  We will need to add support to pdf files conversion. For now, 
	//  we launch the python script for each file and produce a txt file. 
	//  Steps
	//  check files extension (must be all the same type) 
	//  if pdf file, create a temporary list of the new converted files 
	//  once its done process them 
	//  
	auto w_begListIter = aFilesNameWithPath.cbegin();
	while (w_begListIter != aFilesNameWithPath.cend())
	{
		const QString& w_fileName = *w_begListIter;
		// call readFile
		readFile(w_fileName, QString("Signature"));

		// ???
		// check for number of command to proceed
	//	size_t w_numCmd = nbOfCmd();

		// check if it exist
// 		if (m_nbOfCmdInFile.find(w_fileName) != m_nbOfCmdInFile.cend())
// 		{
// 			continue; // not sure about this one!!
// 		}
// 		
// 		m_nbOfCmdInFile.insert( std::make_pair(*w_begListIter, w_numCmd));

		// push m_mapIntVec into vector
		// vector provide a push_back() that support the move semantic  
		// since we don't need the content of the map for next iteration
		// might as well to move its content, is that make sense?
		// don't copy something that i am not going to use 
		m_fileLoaded.push_back( std::move(m_vecCmdText)); // can i do that? why not

	  // sanity check
		//assert(0 == m_vecCmdText.size()); // according to the move semantic
		++w_begListIter; // next in the list
	}

	// now supporting multiple file selection from user
}