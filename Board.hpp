#include <string>
#include "Direction.hpp"
#include <vector>

namespace ariel{
		class Board{
	
		private:
			unsigned int max_row;
			unsigned int max_column;
			std::vector<std::vector<char>> message_board;


		public:
			void post(unsigned int row_loc,unsigned int column_loc, Direction direction, std::string ad_data);
        	std::string read(unsigned int row_loc,unsigned int column_loc, Direction direction,unsigned int ad_len);
        	void show();
			Board();

	};
}