#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define FLAG_DEFAULT	0b00000000
# define FLAG_MINUS		0b00000001
# define FLAG_ZERO		0b00000010
# define FLG_C			0b00000001
# define FLG_S			0b00000010
# define FLG_P			0b00000100
# define FLG_DI			0b00001000
# define FLG_U			0b00010000
# define FLG_SMALL_X	0b00100000
# define FLG_BIG_X		0b01000000
# define FLG_PERCENT	0b10000000

typedef struct		s_printf_list
{
	unsigned char	bit_flag_flag;
	int				width;
	int				no_precision;
	int				precision;
	unsigned char	bit_flag_spec;
	va_list			arg_pointer;
	char			*save_str;
	char			*str;
	int				ret;
}					t_printf_list;

int					ft_atoi(const char *s);
size_t				get_num_length(size_t num);
char				*ft_itoa(int n);
char				*ft_utoa(unsigned int n);
int					ft_max(int x, int y);
int					ft_min(int x, int y);
int					ft_printf(const char *format, ...);
void				ft_putchar_fd(char c, int fd, t_printf_list *printf_list);
void				ft_putstrn(char *str, int len, t_printf_list *printf_list);
size_t				ft_strlen(const char *string);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*get_hex_string(unsigned int num);
char				*get_long_hex_string(unsigned long long num);
char				*get_big_hex_string(size_t num);
int					new_printf(t_printf_list *printf_list);
void				set_default_params(t_printf_list *printf_list);
void				set_new_params(t_printf_list *printf_list);
int					parse(t_printf_list *printf_list);
void				parse_width_foo(t_printf_list *printf_list);
void				parse_parce_foo(t_printf_list *printf_list);
void				parse_parce_foo2(t_printf_list *printf_list, size_t *count);
void				flg_c(t_printf_list *printf_list);
void				flg_di(t_printf_list *printf_list);
void				operate_zeros(t_printf_list *printf_list);
void				flg_p(t_printf_list *printf_list);
void				flg_per(t_printf_list *printf_list);
void				flg_s(t_printf_list *printf_list);
void				flg_u(t_printf_list *printf_list);
void				flg_small_x(t_printf_list *printf_list);
void				flg_big_x(t_printf_list *printf_list);
int					process(t_printf_list *printf_list);
char				*operate_prec(t_printf_list *printf_list, char *str,
													int str_len, int minus);

#endif
