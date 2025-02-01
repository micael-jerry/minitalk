/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:40:17 by mfidimal          #+#    #+#             */
/*   Updated: 2025/02/01 09:53:36 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define INT_MIN_VALUE -2147483648
# define INT_MAX_VALUE 2147483647

# include <stdlib.h>
# include <unistd.h>

typedef struct s_str_trim_info
{
	size_t			start;
	size_t			end;
}					t_str_trim_info;

typedef struct s_ft_itoa_int_info
{
	size_t			intlen;
	int				is_positive;
	int				absolute_value;
}					t_ft_itoa_int_info;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// LIBC
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *ptr, int val, size_t size);
void				ft_bzero(void *ptr, size_t size);
void				*ft_memcpy(void *ptr, const void *src, size_t size);
void				*ft_memmove(void *ptr, const void *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *mem_block, int chr, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
long				ft_atoi(const char *str);
void				*ft_calloc(size_t n, size_t size);
char				*ft_strdup(const char *str);
// ADDITIONAL
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char sep);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
// BONUS
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
// MATRIX
size_t				ft_matrixsize(void **arr);
void				ft_matrixfree(void **arr);

// BINARY
char				*char_to_binary_str(unsigned char c);
char				*str_to_binary_str(char *str);
char				binary_to_char(char *binary);

#endif
