/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:57:22 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/12/11 14:21:22 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* doubled linked list structure */
typedef struct s_list
{
	struct s_list	*previous;
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * basic standard functions 
**/
int		ft_atoi(const char *nptr);

double	ft_atod(char *np);

void	ft_bzero(void *src, size_t n);

void	*ft_calloc(size_t count, size_t size);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

char	*ft_itoa(int n);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

void	*ft_memchr(void *src, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memset(void *b, int c, size_t len);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *src, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(char *src, int fd);

/* cuts src string each time a character in set is found, 
	all resultant strings are returned in an array */
char	**ft_split(char const *src, const char *set);

char	*ft_strchr(const char *src, int c);

char	*ft_strdup(const char *src);

char	*ft_strjoin(char const *s1, const char *s2);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlen(const char *src);

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char));

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(char *big, const char *little, size_t len);

char	*ft_strrchr(const char *src, int c);

char	*ft_strtrim(char const *src, char const *set);

char	*ft_substr(char const *src, size_t start, size_t len);

int		ft_tolower(int c);

int		ft_toupper(int c);

/**
 * linked list related functions
**/

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **alst, t_list *node);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

t_list	*ft_lstfirst(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *node);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));

/**
 * More
**/

/* When called a line of fd is returned, returns 1 if success, 
	0 when there is nothing more to return and -1 if an error ocurred */
int		ft_get_next_line(int fd, char **line);

#endif