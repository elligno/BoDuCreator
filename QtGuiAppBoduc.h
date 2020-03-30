#pragma once

// C++ includes
#include <string>
#include <vector>
#include <list>
#include <map>

// Qt includes
#include <QtWidgets/QMainWindow>
#include <QtCore/QStringList>
#include <QtCore/QDir>
#include <QStringList>

#include "ui_QtGuiAppBoduc.h"

// App. includes
#include "BdAPI/BoDucCmdData.h"
#include "BdAPI/BoDucApp.h"

/**
* Brief BoDuc GUI application, BoDucReportCreator Trademark. 
*   Help dispatcher on daily task of parsing command
*   that flow in and generate a report to delivery truck.  
*    
*/
class QtGuiAppBoduc : public QMainWindow
{
	Q_OBJECT

	// make thing clear
	using cmd2Text = QStringList;
// 	struct cmdInText {
// 		QStringList m_cmd2Text;
// 	};
// 	using cmd2Text = cmdInText;
	using cmdInFile = QVector<cmd2Text>;
	using filesLoaded = QVector<cmdInFile>;

public:
	/** 
	  Set the capacity load according to time period of the year
	 */
	enum class eCapacityMode
	{
		normal = 0, // default mode (most of the year)
		degel = 1   // usually spring time
	};

	/** ... */
	enum class eDisplayMode
	{
		all = 0, // display all cmd from file
		date = 1, // display cmd from user selection date
		dateRange = 2 // display cmd form a date range 
	};

	/**
	*  constructor
	*/
	QtGuiAppBoduc( QWidget *parent = Q_NULLPTR);

	// dtor ??
	// copy and assignment ctor

public slots:
  // user selected files
	void loadCmdFiles();
  void processCmdFiles();

private:
	QStringList m_vecfilePath;         /**< */
	QString m_fileName;                /**< */
	QStringList m_filesName;           /**< list of all csv files name*/
	QDir m_workDir;                    /**< */
	//std::string m_bonLivraison;
	bdAPI::BoDucCmdData m_readPrm;     /**< */
 	cmdInFile m_vecCmdText;            /**< all command in a file*/
	filesLoaded m_fileLoaded;

	
	/** */
	//TODO: shall be done in a config file (user can modify without building the app) 
	QStringList m_listUniteAvailable =
	{ QString("Unit 30"), QString("Unit 33"),
		QString("Unit 103"), QString("Unit 110"), QString("Unit 111"),
		QString("Unit 112"), QString("Unit 114"), QString("Unit 115"),
		QString("Unit 116"), QString("Unit 117")
	};

	/** */
	QStringList m_listValidTransporteur = { QString("NIR R-117971-3 TRSP CPB INC"), QString("BODUC- ST-DAMASE"),
		QString("NIR R-117971-3 TRANSPORT CPB"), QString("NIR R-117971-3 C.P.B."), 
		QString("BODUC- ST-DAMASE"),QString("NIR R-004489-2 TR. BO-DUC")};

	// hold a vector of cmd for each unit (create bon livraison)
	//mapunitfileds m_cmdUnitSaved; //??
	int m_unitIndex = 0;                            /**< */

	//std::list<tplunitAndLoad> m_listLoadValuesPerUnit;
	QString m_currentUnite;                         /**< */
	QList<QVector<QVariant>> m_read4test;           /**< */
	QVector<bdAPI::BoDucCmdData> m_vectorOfCmd;      /**<  all cmd from file*/
	QVector<bdAPI::BoDucCmdData> m_vecOfCmd2Display; /**< selected cmd from user */

	/**
	 *  User select files with mouse
	 */
	void selectFiles();
	/**
	 *  ...
	*/
	void setMode();
  /**
	 *  ...
	*/
	void currentUniteON();

  /**
	 *  ...
	*/
	void unitLoadConfig();
	/**
	*  ...
	*/
	void setUnitCapacityLoad();
	/**
	*  ...
	*/
	void saveDataIntoTable();
	/**
	*  ...
	*/
	void setTableWidgetBox();
	/**
	*  Progress bar updated as dispatcher fill bon livraison
	*/
	void updateProgress();
	/**
	*  ...
	*/
	bool updateUnitProgress(const float aVal2Update);
	/**
	*  ...
	*/
	void initProgressBar();
	// deprecated, removed in the next refactoring 
	void createDataReport();

	/**
	*  parse and fill data structure (one file)
	*/
	void readFile( const QFile& aFileAnPath, const QString& aSplitBill = "Ordered on");

	/**
	*  parse and fill data structure (many files)
	*/
	void readFiles(const QStringList& aFilesNameWithPath,
		const std::string& aSplitBill = "Ordered on");

	/**
	*  
	*/
	void resetContainerData(const QFile& aFileAnPath);

	// UI
	Ui::QtGuiAppBoducClass ui;
};