# include "tester.h"

t_result	run_cub3d(char **argv)
{
	t_result	res;

	bzero(&res, sizeof(t_result));
	if (exec_program(&res, argv) == -1)
		cr_assert_fail("System error: couldn't execute test");
	return (res);
}
