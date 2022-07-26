#include "fdf.h"

int	deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int     main(int argc, char **argv)
{
	fdf	*data;
	size_t i;
	size_t j;

	data = (fdf *)malloc(sizeof(fdf));
	read_file("color.txt", data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

	bresenham_algorithm(10, 10, 600, 300, data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
	
 	i = 0; //map
	while(i < data->height)
	{
		j = 0;
		while(j < data->width)
		{
			printf("%3ld", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

/* #include "fdf.h"

typedef struct    s_data t_data;
typedef struct    s_data
{
    void    *img;
    char    *addr;
    int        bits_per_pixel;
    int        line_length;
    int        endian;
}    t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int    main(int argc, char *argv[])
{
    void    *mlx;
    void    *mlx_win;
    t_data    img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
} */