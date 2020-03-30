#pragma once

#include "BoDucBonLivraisonAlgorithm.h"

namespace bdAPI 
{
	class PdfMinerAlgo : public BoDucBonLivraisonAlgorithm
	{
	public:
		PdfMinerAlgo() {}
		~PdfMinerAlgo() {}
		void fillBoDucFields( const std::vector<std::string>& aCmdVec, BoDucCmdData& aBoDucField) override;
		void addBoDucField( const BoDucCmdData& aField2Add) override;
		virtual bool containsBoDucField(const BoDucCmdData& aField2Look);
		virtual bool removeBoDucField(const BoDucCmdData& aField2);
		virtual void getBoDucStruct(std::vector<BoDucCmdData>& aVec2Fill);
		virtual  size_t getnbOfCmd();
	private:
		std::vector<BoDucCmdData> m_vecOfStruct;
	};
} // End of namespace
