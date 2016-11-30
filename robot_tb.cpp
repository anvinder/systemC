#include "robot_part.h"

int sc_main(int argc, char* argv[]) 
{
	sc_signal <bool> clk;
	sc_signal < sc_int <8> > obstacle1x,obstacle1y, obstacle2x,obstacle2y, obstacle3x, obstacle3y ;	
	sc_signal < sc_int <8> > robot1x, robot1y, robot2x, robot2y, robot3x, robot3y ;
	sc_signal < sc_int<4> > count1, count2, count3;
	//sc_clock clock("Clock",1,SC_NS);
	//sc_clock dist_x("dist_x",1,SC_NS);

	robot_part rs("robot");

	rs.robot1x(robot1x);		rs.robot1y(robot1y);
	rs.robot2x(robot2x);		rs.robot2y(robot2y);
	rs.robot3x(robot3x);		rs.robot3y(robot3y);
	rs.obstacle1x(obstacle1x);	rs.obstacle1y(obstacle1y);
	rs.obstacle2x(obstacle2x);	rs.obstacle2y(obstacle2y);
	rs.obstacle3x(obstacle3x);	rs.obstacle3y(obstacle3y);
	rs.clk(clk);			    rs.count1(count1);
	rs.count2(count2);          rs.count3(count3);

	sc_trace_file *file;
	file = sc_create_vcd_trace_file("robot");
	//file->set_time_unit(1, SC_NS);

	sc_trace(file, clk, "clock");				
	sc_trace(file, robot1x, "robot1x");			sc_trace(file, robot1y, "robot1y");
	sc_trace(file, robot2x, "robot2x");			sc_trace(file, robot2y, "robot2y");
	sc_trace(file, robot3x, "robot3x");			sc_trace(file, robot3y, "robot3y");
	sc_trace(file, obstacle1x, "obstacle1x");	sc_trace(file, obstacle1y, "obstacle1y");
	sc_trace(file, obstacle2x, "obstacle2x");	sc_trace(file, obstacle2y, "obstacle2y");
	sc_trace(file, obstacle3x, "obstacle3x");	sc_trace(file, obstacle3y, "obstacle3y");
	sc_trace(file, count1, "count1");			sc_trace(file, count2, "count2");
	sc_trace(file, count3, "count3");


	robot1x=1;
	robot1y=1;
	obstacle1x=0;
	obstacle1y=0;

	robot2x=1;
	robot2y=52;
	obstacle2x=0;
	obstacle2y=0;

	robot3x=36;
	robot3y=1;
	obstacle3x=0;
	obstacle3y=0;

	count3=1;

	for (int i = 0; i<=250; i++)
{
    clk = 0; 
    sc_start(1, SC_NS);
    clk = 1; 
    sc_start(1, SC_NS);
};

	/*
	obstacle1x=0;
	obstacle1y=0;
	obstacle2x=0;
	obstacle2y=0;
	obstacle3x=0;
	obstacle3y=0;
	count2=0;
	for (int i = 61; i<=80; i++)
{
    clk = 0; 
    sc_start(1, SC_NS);
    clk = 1; 
    sc_start(1, SC_NS);
};

	obstacle1x=0;
	obstacle1y=0;
	obstacle2x=0;
	obstacle2y=0;
	obstacle3x=0;
	obstacle3y=0;
	count2=0;
	for (int i = 81; i<=180; i++)
{
    clk = 0; 
    sc_start(1, SC_NS);
    clk = 1; 
    sc_start(1, SC_NS);
};
*/

//sc_start(800, SC_NS);
sc_close_vcd_trace_file(file);
sc_stop();
return (0);

}
