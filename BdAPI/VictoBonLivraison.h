#pragma once

#include "BoDucBonLivraisonAlgorithm.h"

namespace bdAPI
{
	class VictoBonLivraison : public BoDucBonLivraisonAlgorithm
	{
		enum class eKeywordType
		{
			CommandNo = 1,
			ShippedTo = 2
		};
	public:
		VictoBonLivraison();
		~VictoBonLivraison();
		void fillBoDucFields( const std::vector<std::string>& aCmdVec, BoDucCmdData& aBoDucField) override;
		void addBoDucField( const BoDucCmdData& aField2Add) override;
		bool containsBoDucField( const BoDucCmdData& aField2Look) override;
		bool removeBoDucField( const BoDucCmdData& aField2) override;
		size_t getnbOfCmd() override { return m_vecOfStruct.size(); }
		void getBoDucStruct( std::vector<BoDucCmdData>& aVec2Fill) override;
	private:
		std::initializer_list<std::string> m_fieldKey;
		std::vector<BoDucCmdData> m_vecOfStruct;
	};
} // End of namespace
