#pragma once

// C++ includes
#include <iostream>
#include <string>
// STL includes
#include <map>
#include <vector>
// Boost includes
#include <boost/operators.hpp>

namespace bdAPI
{
	struct BoDucCmdData : public boost::equality_comparable<BoDucCmdData>,
		public boost::less_than_comparable<BoDucCmdData>
	{
		// alias <cmdNo, shippedTo, deliveryDate,prod code, prod, qty,silo>
		using bdTpl = std::tuple<std::string, std::string, std::string, long, std::string,float, std::string>;
		
		// default ctor
		BoDucCmdData();
		//move semantic
		BoDucCmdData( bdTpl&& aTpl);

		friend bool operator== (const BoDucCmdData& aField1, const BoDucCmdData& aField2)
		{
			return (aField1.m_noCmd == aField2.m_noCmd) ? true : false;
		}
		friend bool operator< (const BoDucCmdData& aField1, const BoDucCmdData& aField2)
		{
			return (aField1.m_datePromise < aField2.m_datePromise) ? true : false;
		}
		friend std::ostream& operator<< (std::ostream& stream, const BoDucCmdData& aBdF)
		{
			stream << aBdF.m_noCmd << " " << aBdF.m_datePromise << " " << aBdF.m_deliverTo <<
				" " << aBdF.m_produit << " " << aBdF.m_prodCode << " " << aBdF.m_silo << " " << aBdF.m_qty << "\n";

			return stream;
		}

		std::string m_noCmd;
		std::string m_deliverTo;
		std::string m_datePromise;
		signed long m_prodCode;
		std::string m_produit;
		float m_qty; // better to set as a string
		//not always an integer (can be 2&3, 4-A and a string such as "Un seul silo")
		std::string m_silo;
	};
} // End of namespace