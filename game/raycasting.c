#include "../cub3d.h"

void	raycast(t_game *game)
{
	//double	dirx = -1;
	//double	dirY = 0;
	double	planeX = 0;
	double	planeY = 0.66;
	int		w = 320;

	for (int x = 0;  x < w; x++)
	{
		double	cameraX = 2 * x / (double)w - 1;
		double	rayDirX = game->ray.delta_x + planeX * cameraX;
		double	rayDirY = game->ray.delta_y + planeY * cameraX;

		int		mapX = (int)game->ray.x;
		int		mapY = (int)game->ray.y;

		double	sideDistX;
		double	sideDistY;

		double	deltaDistX;
		double	deltaDistY;
		//double	perpWallDist;

		int		stepX;
		int		stepY;

		int		hit = 0;
		int		side;

		if  (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs(1 / rayDirX);
		if  (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1 / rayDirY);

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->ray.x - mapX) * deltaDistX;
		}
		else{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->ray.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->ray.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->ray.y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (game->map[mapY / 20][mapX / 20] == '1')
				hit = 1;
			//printf("player X: %f, player Y: %f, Hit X: %f, Hit Y: %f\n", game->ray.x, game->ray.y, sideDistX, sideDistY);
			drawline(game, game->ray.x, game->ray.y, mapX, mapY);
		}
	}


}
void	clearcast(t_game *game)
{
	//double	dirx = -1;
	//double	dirY = 0;
	double	planeX = 0;
	double	planeY = 0.66;
	int		w = 512;

	for (int x = 0;  x < w; x++)
	{
		double	cameraX = 2 * x / (double)w - 1;
		double	rayDirX = game->ray.delta_x + planeX * cameraX;
		double	rayDirY = game->ray.delta_y + planeY * cameraX;

		int		mapX = (int)game->ray.x;
		int		mapY = (int)game->ray.y;

		double	sideDistX;
		double	sideDistY;

		double	deltaDistX;
		double	deltaDistY;
		//double	perpWallDist;

		int		stepX;
		int		stepY;

		int		hit = 0;
		int		side;

		if  (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs(1 / rayDirX);
		if  (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1 / rayDirY);

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->ray.x - mapX) * deltaDistX;
		}
		else{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->ray.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->ray.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->ray.y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (game->map[mapY / 20][mapX / 20] == '1')
				hit = 1;
			//printf("player X: %f, player Y: %f, Hit X: %f, Hit Y: %f\n", game->ray.x, game->ray.y, sideDistX, sideDistY);
			clearline(game, game->ray.x, game->ray.y, mapX, mapY);
		}
	}

}