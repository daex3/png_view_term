#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <reader_png.c>
#include <signal.h>
#include <string.h>

#define PIXELS

#include <tegrine/instances.c>

void die(int _) {
	(void)_;

	puts("\x1b[?25h\x1b[m\x1b[2J"),
	exit(-1);
}

Tegrine te;
Pixels g;

void update(int _) {
	(void)_;

	// Resize fullscreen
	set_ws(&te.ws),
	resize_pixels(&g, &te.ws),

	fputs("\x1b[?25l\x1b[2J", stdout),
	draw_pixels(&te.ws, &g, 0),
	fflush(stdout);
}

int main(int argc, char **argv) {
	if (argc < 2)
		puts("\x1b[36mUsage:\x1b[m png_view_term file.png"),
		exit(-1);

	g = read_png(argv[1]),
	update(0),

	signal(SIGINT, die),
	signal(SIGWINCH, update);

	for(;;)
		pause();
}
