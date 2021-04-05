#include <string>
#include "Board.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

Board message_board_basic;
Board message_board;

TEST_CASE("basic checks for post and read functions")
{
    //10 rows 20 columns
	CHECK_NOTHROW(message_board_basic.post(0, 0, Direction::Horizontal,"row number zero     "));
    CHECK_NOTHROW(message_board_basic.post(1, 0, Direction::Horizontal,"row number one      "));
    CHECK_NOTHROW(message_board_basic.post(2, 0, Direction::Horizontal,"row number two      "));
    CHECK_NOTHROW(message_board_basic.post(3, 0, Direction::Horizontal,"row number three    "));
    CHECK_NOTHROW(message_board_basic.post(4, 0, Direction::Horizontal,"row number four     "));
    CHECK_NOTHROW(message_board_basic.post(5, 0, Direction::Horizontal,"row number five"));
    CHECK_NOTHROW(message_board_basic.post(6, 0, Direction::Horizontal,"row number six"));
    CHECK_NOTHROW(message_board_basic.post(7, 0, Direction::Horizontal,"row number seven"));
    CHECK_NOTHROW(message_board_basic.post(8, 0, Direction::Horizontal,"row number eight"));
    CHECK_NOTHROW(message_board_basic.post(9, 0, Direction::Horizontal,"row number nine"));
  
	CHECK(message_board_basic.read(0, 0, Direction::Horizontal, 20) == string("row number zero     "));
	CHECK(message_board_basic.read(1, 0, Direction::Horizontal, 20) == string("row number one      "));
	CHECK(message_board_basic.read(2, 0, Direction::Horizontal, 20) == string("row number two      "));
	CHECK(message_board_basic.read(3, 0, Direction::Horizontal, 20) == string("row number three    "));
	CHECK(message_board_basic.read(4, 0, Direction::Horizontal, 20) == string("row number four     "));
	CHECK(message_board_basic.read(5, 0, Direction::Horizontal, 20) == string("row number five_____"));
	CHECK(message_board_basic.read(6, 0, Direction::Horizontal, 20) == string("row number six______"));
	CHECK(message_board_basic.read(7, 0, Direction::Horizontal, 20) == string("row number seven____"));
	CHECK(message_board_basic.read(8, 0, Direction::Horizontal, 20) == string("row number eight____"));
	CHECK(message_board_basic.read(9, 0, Direction::Horizontal, 20) == string("row number nine_____"));
}

TEST_CASE("post check basic")
{
	CHECK_NOTHROW(message_board_basic.post(10, 0, Direction::Horizontal,"row number ten"));
	CHECK_NOTHROW(message_board_basic.post(11, 0, Direction::Horizontal,"row number eleven"));
	CHECK_NOTHROW(message_board_basic.post(12, 0, Direction::Horizontal,"row number twelve"));
}

TEST_CASE("read check basic")
{
	CHECK(message_board_basic.read(10, 0, Direction::Horizontal, 20) == string("row number ten______"));
	CHECK(message_board_basic.read(11, 0, Direction::Horizontal, 20) == string("row number eleven___"));
	CHECK(message_board_basic.read(12, 0, Direction::Horizontal, 20) == string("row number twelve___"));
	CHECK(message_board_basic.read(0, 11, Direction::Vertical, 13) == string("zottffssentet"));
	CHECK(message_board_basic.read(0, 0, Direction::Vertical, 13) == string("rrrrrrrrrrrrr"));
	CHECK(message_board_basic.read(0, 19, Direction::Vertical, 13) == string("     ________"));
	CHECK(message_board_basic.read(0, 4, Direction::Horizontal, 6) == string("number"));
}

TEST_CASE("special cases")
{
	//read a new board with no postes yet
	CHECK(message_board.read(0, 0, Direction::Horizontal, 1) == string("_"));
	CHECK(message_board.read(0, 10, Direction::Vertical, 10) == string("__________"));
	CHECK(message_board.read(100, 100, Direction::Vertical, 1) == string("_"));
	//read 0 letters
	CHECK(message_board.read(0, 0, Direction::Horizontal, 0) == string(""));
	CHECK(message_board.read(0, 0, Direction::Vertical, 0) == string(""));
	//read after posting two posts in the same location 
	CHECK_NOTHROW(message_board.post(0, 0, Direction::Horizontal,"first post"));
	CHECK_NOTHROW(message_board.post(0, 0, Direction::Horizontal,"second"));
	CHECK(message_board.read(0, 0, Direction::Horizontal, 10) == string("secondpost"));
	//post and read in the corners
	CHECK_NOTHROW(message_board.post(1, 0, Direction::Horizontal,"random post"));
	CHECK(message_board.read(1, 10, Direction::Horizontal, 3) == string("t__"));
	CHECK(message_board.read(0, 9, Direction::Vertical, 6) == string("ts____"));
	CHECK(message_board.read(0, 10, Direction::Vertical, 6) == string("_t____"));
	//post and read uppercase letters
	CHECK_NOTHROW(message_board.post(2, 0, Direction::Horizontal,"UPPERcase ChEcKs"));
	CHECK(message_board.read(2, 4, Direction::Horizontal, 3) == string("Rca"));
	//post and raed special letters
	CHECK_NOTHROW(message_board.post(3, 0, Direction::Horizontal,"!@#$%^&*()"));
	CHECK(message_board.read(3, 0, Direction::Horizontal,10) == string("!@#$%^&*()"));
}
