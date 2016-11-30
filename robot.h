#include "systemc.h"

SC_MODULE(robot_part)
{
	sc_in <bool> clk;
	sc_out <sc_int<8> > robot1x, robot1y, robot2x, robot2y, robot3x, robot3y ;
	sc_in <sc_int<8> > obstacle1x, obstacle1y, obstacle2x, obstacle2y, obstacle3x, obstacle3y;
	sc_in <sc_int<4> > count1, count2, count3;
	//sc_fifo_out <float> robot1x, robot1y, robot2x, robot2y, robot3x, robot3y ;
	//sc_fifo_in <float> obstacle1x, obstacle1y, obstacle2x, obstacle2y, obstacle3x, obstacle3y;

	//sc_fifo <float>  temp_robot1x, temp_robot1y, temp_robot2x,temp_robot2y, temp_robot3x, temp_robot3y ;
	//sc_fifo <float> temp_obstacle1x, temp_obstacle1y, temp_obstacle2x, temp_obstacle2y, temp_obstacle3x, temp_obstacle3y;

	sc_int <8>  temp_robot1x, temp_robot1y, temp_robot2x,temp_robot2y, temp_robot3x, temp_robot3y ;
	sc_int<8> temp_obstacle1x, temp_obstacle1y, temp_obstacle2x, temp_obstacle2y, temp_obstacle3x, temp_obstacle3y;

	sc_int<4> temp_count1, temp_count2, temp_count3;

	void move_robot1();
	void move_robot2();
	void move_robot3();

	SC_CTOR(robot_part) 
	{
		//SC_THREAD (move);
		SC_METHOD (move_robot1);
		sensitive<<clk.pos();

		SC_METHOD (move_robot2);
		sensitive<<clk.pos();

		SC_METHOD (move_robot3);
		sensitive<<clk.pos();
	}

};
