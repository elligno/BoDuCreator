#pragma once

#include "BoDucCsvReader.h"

namespace bdAPI
{

	/**
	* Brief Implementation that
	*   Design Note inherit from
	*/
	class VictoReader : public BoDucReader
	{
	public:
		// alias
		using vecofstr = std::vector<std::string>;
	public:
		/**
		*  constructor
		*/
		VictoReader();
		/**
		*  destructor
		*/
		~VictoReader();

		// deprecated
		virtual void readNoCmd(const vecofstr& aCmdVec, BoDucCmdData& aBoducF) override;
		
		// new version
		virtual void readNoCmd( const std::string& aCmdVec, BoDucCmdData& aBoducF) override;
		virtual void readShippedTo( const vecofstr& aFieldValue, BoDucCmdData& aBoducF) override;
		virtual void readDeliveryDate(const std::string& aFiedValue, BoDucCmdData& aBoducF) override;
		virtual void readProdDescr(const std::string& aCmdVec, BoDucCmdData& aBoducF) override;
		virtual void readQtySilo(const std::string & aFieldValue, BoDucCmdData& aBoducF) override;
		virtual void readProdCode(const std::string& aFieldValue, BoDucCmdData& aBoducF) override;
		// shall be in the base class
		size_t nbOfCmd(const std::string& aCmdFile) const;
	protected:
		// rebuild complete address algorithm (not really generic)
		// In the present case we have done most test with billing 
		// from Victo. But the current algorithm may not apply to 
		// other source of billing, like parisville or ...
		virtual std::string rebuildShippedTo( const vecofstr& aAddressPart);
		std::size_t m_nbCmd = 0;
	};
} // End of namespace

