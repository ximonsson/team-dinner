
void setup ()
{

}

struct led
{
	int pin;
	int phase;
	int counter;
	byte brightness;
	byte dir;
};

void step_led (struct led *l)
{
	l->counter ++;

	if (l->counter >= l->phase)
	{
		// step brightness
		l->brightness += l->dir;

		// switch direction if needed
		if (l->brightness == 255 || l->brightness == 0)
			l->dir = - l->dir;

		// reset counter
		l->counter = 0;

		// update brightness
		analogWrite (l->pin, l->brightness);
	}
}

struct led l1 {
	3,
	500,
	0,
	0,
	1
};

struct led l2 {
	5,
	750,
	0,
	0,
	1
};

struct led l3 {
	6,
	1000,
	0,
	0,
	1
};

void loop ()
{
	step_led (&l1);
	step_led (&l2);
	step_led (&l3);
}
