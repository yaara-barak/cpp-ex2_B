#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace ariel;

	Board::Board()
    {
        max_row = 0;
        max_column = 0;
		message_board.push_back(vector<char>(1,'_'));
    }

	void Board::post(unsigned int row_loc,unsigned int column_loc, Direction direction, string ad_data)
    {
		if(ad_data.length()==0){
			return;
		}
		
		//if the row location for post is bigger then numbers of rows
		if(max_row<row_loc){
			for(unsigned int i=0;i<=(row_loc-max_row)-1;i++){
				message_board.push_back(vector<char>(max_column+1,'_'));
			}
			max_row=row_loc;
			}
		//if the column location for post bigger then the numbers of columns
		if(max_column<column_loc){
			for(unsigned int i=0;i<=max_row;i++){
				for(unsigned int j=0; j<=(column_loc-max_column)-1;j++){
					message_board.at(i).push_back('_');
				}
			}
			max_column=column_loc;
		}

		unsigned int index_in_string=0;
		
		if(direction==Direction::Horizontal){
			//if the message length bigger then the numbers of columns
			if(max_column<(column_loc+ad_data.length()-1)){
				for(unsigned int i=0;i<=max_row;i++){
					for(unsigned int j=max_column; j<=(column_loc+ad_data.length()-1);j++){
						message_board.at(i).push_back('_');
					}
				}
				max_column=column_loc+ad_data.length()-1;
			}
			//post the message
			for (unsigned int j=column_loc;j<=(column_loc+ad_data.length()-1);j++){
				message_board.at(row_loc).at(j)=ad_data.at(index_in_string);
				index_in_string++;
			}
		}
		else{
			//if the message length bigger then the numbers of columns
			if(max_row<(row_loc+ad_data.length()-1)){
				for(unsigned int i=max_row;i<=(row_loc+ad_data.length()-1);i++){
					message_board.push_back(vector<char>(max_column+1, '_'));
				}
				max_row= row_loc+ad_data.length()-1;
			}
			//post the message	
			for (unsigned int i=row_loc;i<=(row_loc+ad_data.length()-1);i++){
				message_board.at(i).at(column_loc)=ad_data.at(index_in_string);
				index_in_string++;
			}
		}
	
	}

	string Board::read(unsigned int row_loc,unsigned int column_loc, Direction direction,unsigned int ad_len)
    {

		string read_ad="";
		//if the length that need to read is 0
		if(ad_len==0){
			return read_ad;
		}
		//if the start place is not exist (row or culumn)
		if((direction==Direction::Horizontal && column_loc>max_column)||(direction==Direction::Vertical && row_loc>max_row)
				||(direction==Direction::Horizontal && row_loc>max_row)||(direction==Direction::Vertical && column_loc>max_column) 
					|| (row_loc>max_row && column_loc>max_column)){
						for(int x=0;x<ad_len;x++){
							read_ad= read_ad+"_";
						}
		   return read_ad;
		}
		//if the we need to read horizontal more lettrs then exist
		if(direction==Direction::Horizontal && max_column<column_loc+ad_len-1){
			for(unsigned int j=0;j<ad_len-(column_loc+ad_len-1-max_column);j++){
					read_ad=read_ad+message_board.at(row_loc).at(column_loc+j);
			}
			for(unsigned int x=0; x<column_loc+ad_len-1-max_column;x++){
				read_ad=read_ad+"_";
			}
		}
		//simple reading
		else{
			if(direction==Direction::Horizontal){
				for (unsigned int j=0;j<ad_len;j++){
					read_ad=read_ad+message_board.at(row_loc).at(column_loc+j);
				}
			}
		}
		//if the we need to read vertical more lettrs then exist
		if(direction==Direction::Vertical && max_row<row_loc+ad_len-1){
			for (unsigned int i=0;i<ad_len-(row_loc+ad_len-1-max_row);i++){
				read_ad=read_ad+message_board.at(row_loc+i).at(column_loc);
			}
			for(unsigned int x=0; x<row_loc+ad_len-1-max_row; x++){
				read_ad=read_ad+"_";
			}
		}
		//simple reading
		else
		{
			if(direction==Direction::Vertical )
			for (unsigned int i=0;i<ad_len;i++){
				read_ad=read_ad+message_board.at(row_loc+i).at(column_loc);
			}
		}
		
		return read_ad;
	}

	void Board::show()
	{
		for (unsigned int i = 0; i <= max_row; i++)
        {
            cout << i << ": ";
            for (unsigned int j = 0; j <= max_column; j++)
            {
                cout << message_board.at(i).at(j);
            }
            cout << endl;
        }
		cout<<"______________________________\n";
	}
	


