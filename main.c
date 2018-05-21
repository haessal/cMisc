#include <stdlib.h>
#include <string.h>
#include "builtin.h"
#include "main.h"

struct cmd_struct {
	const char *cmd;
	int (*fn)(int argc, const char **argv);
};

static void handle_options(int *argcp, const char ***argvp);
static int handle_builtin(int argc, const char **argv);
static struct cmd_struct *get_builtin(const char *s);
static int run_builtin(struct cmd_struct *p, int argc, const char **argv);

int cmisc_main(int argc, const char **argv)
{
	int status;

	argv++;
	argc--;
	handle_options(&argc, &argv);
	if (argc > 0) {
		status = handle_builtin(argc, argv);
	} else {
		status = EXIT_FAILURE;
	}
	return status;
}

static void handle_options(int *argcp, const char ***argvp)
{
	return;
}

static int handle_builtin(int argc, const char **argv)
{
	int status;
	struct cmd_struct *builtin;

	builtin = get_builtin(argv[0]);
	if (builtin != NULL) {
		status = run_builtin(builtin, argc, argv);
	} else {
		status = EXIT_FAILURE;
	}
	return status;
}

static struct cmd_struct commands[] = {
	{ "help", cmd_help },
	{ 0, 0}
};
static struct cmd_struct *get_builtin(const char *s)
{
	int i;
	struct cmd_struct *p;

	for (i = 0; commands[i].cmd != 0; i++) {
		p = commands + i;
		if (!strcmp(s, p->cmd)) {
			return p;
		}
	}
	return NULL;
}

static int run_builtin(struct cmd_struct *p, int argc, const char **argv)
{
	return p->fn(argc, argv);
}
