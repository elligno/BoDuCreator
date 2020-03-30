#pragma once

#include "BoDucCsvReader.h"

namespace bdAPI 
{
	class PdfMinerReader : public BoDucReader
	{
	public:
		// alias
		using vecofstr = std::vector<std::string>;
	public:
		PdfMinerReader() {}
		~PdfMinerReader() {}
		
		// ...
		virtual void readNoCmd(const vecofstr& aCmdVec, BoDucCmdData& aBoducF) override {/*no implemenetation*/}
		virtual void readNoCmd(const std::string& aCmdVec, BoDucCmdData& aBoducF) override {/*no implemenetation*/ }
		// 
		virtual void readShippedTo(const vecofstr& aFieldValue, BoDucCmdData& aBoducF) override;
		virtual void readDeliveryDate(const std::string& aFiedValue, BoDucCmdData& aBoducF) override;
		virtual void readProdDescr(const std::string& aCmdVec, BoDucCmdData& aBoducF) override {}
		virtual void readQtySilo(const std::string & aFieldValue, BoDucCmdData& aBoducF) override {}
		virtual void readProdCode(const std::string& aFieldValue, BoDucCmdData& aBoducF) override {}
	};
} // End of namespace
