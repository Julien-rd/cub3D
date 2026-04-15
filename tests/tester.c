#include <criterion/criterion.h>
#include "tester.h"

t_result	run_cub3d(char *file)
{
	t_result	res;
	char		*argv[3] = {"./cub3D", NULL, NULL};

	bzero(&res, sizeof(t_result));
	argv[1] = file;
	exec_program(&res, argv);
	return (res);
}

Test(cub3d, empty_file)
{
	t_result res = run_cub3d("./maps/invalid/empty.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nEmpty file !\n");
}

Test(cub3d, no_map)
{
	t_result res = run_cub3d("./maps/invalid/no_map.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nNo map found!\n");
}

Test(cub3d, wrong_extension)
{
	t_result res = run_cub3d("./maps/invalid/invalid_extension.cubbb");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\ninvalid input format\n");
}

Test(cub3d, missing_texture)
{
	t_result res = run_cub3d("./maps/invalid/missing_texture.cub");

	cr_assert_eq(res.exit_code, 1);
	cr_assert_str_eq(res.stderr, "Error\nNo path found!\n");
}
