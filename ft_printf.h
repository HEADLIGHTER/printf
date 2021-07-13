#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "/libft/libft.h"

int		ft_printf(const char *say_the_line_JC, ...);
void	ft_putstr(char *s);
void	dtohex(unsigned int n, char *base, size_t *count);
void	pout(void *arg, char *base, size_t *count);
void	*ft_uitoa(unsigned int n);
void	pnull(size_t *count);

#endif
