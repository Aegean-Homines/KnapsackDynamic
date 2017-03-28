#include "knapsack-dp.h"
#include <iostream>
#include <numeric>
#include <algorithm>

typedef std::vector<std::vector<int>> Table;

////////////////////////////////////////////////////////////
Item::Item( int const& weight, int const& value ) 
	: weight(weight), value(value) 
{
}

////////////////////////////////////////////////////////////
Item::Item( Item const& original ) 
	: weight(original.weight), value(original.value)
{
}

////////////////////////////////////////////////////////////
std::ostream& operator<< (std::ostream& os, Item const& item) {
	os << "(" << item.weight << " , " << item.value << ") ";
	return os;
}

////////////////////////////////////////////////////////////
std::istream& operator>> (std::istream& os, Item & item) {
	os >> item.weight >> item.value;
	return os;
}

////////////////////////////////////////////////////////////
typedef std::vector< std::vector<int> > Table; //2-dimensional table

////////////////////////////////////////////////////////////
//the returned value is a vector of indices
std::vector<int> knapsackDP( std::vector<Item> const& items, int const& W ) {
	int num_items = items.size();
	Table table(W + 1, std::vector<int>(items.size() + 1, 0));

	for (int i = 1; i <= items.size(); ++i) {
		for (int w = 1; w <= W; ++w) {
			Item const & item = items[i-1];
			if (w >= item.weight)
				table[w][i] = std::max(table[w][i - 1], table[w - item.weight][i - 1] + item.value);
			else
				table[w][i] = table[w][i - 1];
		}
	}
	
    /*  ........... */

	//print final table - for debugging?
    //do not delete this code
    if ( num_items + W < 50 ) { //print only if table is not too big
        std::cout << "   ";
        for ( int n=0; n<=num_items; ++n) { std::cout << n << "     "; }
        std::cout << "  items\n        ";
        for ( int n=0; n<num_items; ++n) { std::cout << items[n].weight << "," << items[n].value<<"   "; }
        std::cout << "\n   ";
        for ( int n=0; n<=num_items; ++n) { std::cout << "------"; }
        std::cout << std::endl;

        for ( int w=0; w<=W; ++w) {
            std::cout << w << "| ";
            for ( int n=0; n<=num_items; ++n) {
                std::cout << table[w][n] << "     ";
            }
            std::cout << std::endl;
        }
    }
    //end do not delete this code 


	//figure out which items are in the bag based on the table
	std::vector<int> bag;
	int remainingWeight = W;
	int itemIndex = num_items - 1;
	while(remainingWeight != 0) {
		Item const & item = items[itemIndex];
		if (table[remainingWeight][itemIndex + 1] != table[remainingWeight][itemIndex]) { // didn't inherit previous value
			bag.push_back(itemIndex);
			remainingWeight -= item.weight;
		}
		--itemIndex;
	}

	return bag;
}

////////////////////////////////////////////////////////////
int valueBag( std::vector<Item> const& items, std::vector<int> const& bag ) {
	std::vector<int>::const_iterator it   = bag.begin(),
		                          it_e = bag.end();

	int accum = 0;
	//std::cout << "Bag ";
	for ( ; it != it_e; ++it) { 
		accum += items[ *it ].value; 
		//std::cout << *it << " ";
	}
	//std::cout << std::endl;
	return accum;
}

////////////////////////////////////////////////////////////
//prototype
//notice that auxiliary function returns value of the vector of items
//the actual vector is determined later from the table (similar to DP solution)
int knapsackRecMemAux( std::vector<Item> const&, int const&, int, Table& );

////////////////////////////////////////////////////////////
//function to kick start
std::vector<int> knapsackRecMem( std::vector<Item> const& items, int const& W ) {
	int num_items = items.size();
	Table table;
    /* ........... */

	//print table - debugging?
    //do not delete this code
    if ( num_items + W < 50 ) { //print only if table is not too big
        std::cout << "   ";
        for ( int n=0; n<=num_items; ++n) { std::cout << n << "     "; }
        std::cout << "  items\n        ";
        for ( int n=0; n<num_items; ++n) { 
            std::cout << items[n].weight << "," << items[n].value<<"   "; 
        }
        std::cout << "\n   ";
        for ( int n=0; n<=num_items; ++n) { std::cout << "------"; }
        std::cout << std::endl;

        for ( int w=0; w<=W; ++w) {
            std::cout << w << "| ";
            for ( int n=0; n<=num_items; ++n) {
                std::cout << table[w][n] << "     ";
            }
            std::cout << std::endl;
        }
    }
    //end do not delete this code 

	//figure out which items are in the bag based on the table
	std::vector<int> bag;
    /* ........... */
	return bag;
}

////////////////////////////////////////////////////////////
//the real recursive function
int
knapsackRecMemAux( std::vector<Item> const& items, int const& W, int index, Table & table ) {
    /* ........... */
	return 0;
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
