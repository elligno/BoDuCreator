#pragma once

#include <vector>

#include "BoDucCmdData.h"

namespace bdAPI
{
	// Base class for all algorithm that parse BoDucStruct 
	// that has been read from a csv file format. To be completed!!
	//
	class BoDucBonLivraisonAlgorithm
	{
	public:
		// shall i provide a virtual dtor??
		virtual ~BoDucBonLivraisonAlgorithm() = default;
		// return the BoDucFields ... to be completed
		virtual void fillBoDucFields( const std::vector<std::string>& aCmdVec, BoDucCmdData& aBoDucField) = 0;
		//TODO create a class VectorBoDucFields which implement these methods
		virtual void addBoDucField( const BoDucCmdData& aField2Add) = 0; // deprecated
		virtual bool containsBoDucField( const BoDucCmdData& aField2Look) = 0; 
		virtual bool removeBoDucField( const BoDucCmdData& aField2) = 0;
		virtual void getBoDucStruct( std::vector<BoDucCmdData>& aVec2Fill) = 0;
		virtual  size_t getnbOfCmd() = 0;
	};
} // End of namespace
