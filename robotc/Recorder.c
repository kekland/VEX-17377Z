#pragma config(Sensor, dgtl1, leftWheelsEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl3, rightWheelsEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl5, liftEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl7, chainBarEncoder, sensorQuadEncoder)
#pragma config(Motor, port1, intake, tmotorVex393_HBridge, openLoop)
#pragma config(Motor, port3, rightWheels, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port5, leftLift, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port6, chainBar, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port7, rightLift, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port8, leftWheels, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port9, claw, tmotorVex393_MC29, openLoop)

float wheelMult = 360.0 / (3.1415926 * 10.16); //360l / 3.14*D
task main()
{
	SensorValue[chainBarEncoder] = 0;
	SensorValue[liftEncoder] = 0;
	SensorValue[leftWheelsEncoder] = 0;
	SensorValue[rightWheelsEncoder] = 0;
	while (true)
	{
		if (vexRT[Btn5U] == 1)
		{
			while (vexRT[Btn5U] != 0)
			{
				delay(10);
			}
			char chainValue[100];
			char rotValue[100];
			char leftValue[100];
			char rightValue[100];
			sprintf(chainValue, "%d", SensorValue[chainBarEncoder]);
			sprintf(rotValue, "%d", SensorValue[liftEncoder]);
			sprintf(leftValue, "%d", SensorValue[leftWheelsEncoder] / wheelMult);
			sprintf(rightValue, "%d", SensorValue[rightWheelsEncoder] / wheelMult);

			writeDebugStream("calculateMovements(");
			writeDebugStream(leftValue);
			writeDebugStream(", ");
			writeDebugStream(rightValue);
			writeDebugStream(", ");
			writeDebugStream(chainValue);
			writeDebugStream(", ");
			writeDebugStream(rotValue);
			writeDebugStream(", false);\n");
		}
		if (vexRT[Btn6U] == 1)
		{
			while (vexRT[Btn6U] != 0)
			{
				delay(10);
			}
			writeDebugStream("intake_up();\n");
		}

		if (vexRT[Btn6D] == 1)
		{
			while (vexRT[Btn6D] != 0)
			{
				delay(10);
			}
			writeDebugStream("intake_down();\n");
		}

		if (vexRT[Btn7U] == 1)
		{
			while (vexRT[Btn7U] != 0)
			{
				delay(10);
			}
			writeDebugStream("claw_up();\n");
		}

		if (vexRT[Btn7D] == 1)
		{
			while (vexRT[Btn7D] != 0)
			{
				delay(10);
			}
			writeDebugStream("claw_down();\n");
		}
	}
}
