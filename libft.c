#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
    char    chr;
    int     i;

    if (!s)
        return (NULL);
    i = 0;
    chr = (char)c;
    while (s[i] != '\0')
    {
        if (s[i] == chr)
            return ((char *)&s[i]);
        i++;
    }
    return (NULL);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
    size_t  srclen;

    srclen = ft_strlen(src);
    if (srclen < maxlen)
        ft_memcpy(dst, src, srclen + 1);
    else if (maxlen != 0)
    {
        ft_memcpy(dst, src, maxlen - 1);
        dst[maxlen - 1] = '\0';
    }
    return (srclen);
}

size_t  ft_strnlen(const char *s, size_t maxlen)
{
    size_t  length;

    length = 0;
    while (s[length] != '\0')
    {
    length++;
    }
    if (length <= maxlen)
        return (length);
    else
        return (maxlen);
}

size_t ft_strlcat(char *dst, const char *src, size_t maxlen)
{
    size_t srclen;
    size_t dstlen;

    srclen = ft_strlen(src);
    dstlen = ft_strnlen(dst, maxlen);
    if (dstlen == maxlen)
        return (maxlen + srclen);
    if (srclen < maxlen - dstlen)
        ft_memcpy(dst + dstlen, src, srclen + 1);
    else
    {
        ft_memcpy(dst + dstlen, src, maxlen - dstlen - 1);
        dst[maxlen - 1] = '\0';
    }
    return (dstlen + srclen);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *p;
    size_t  len;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    p = (char *)malloc(len);
        if (!p)
            return (NULL);
    ft_strlcpy(p, s1, len);
    ft_strlcat(p, s2, len);
    return (p);
}

size_t    ft_strlen(const char *s)
{
    int    length;

    length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    return (length);
}
void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    char        *p1;
    const char    *p2;

    if (dst == NULL && src == NULL)
        return (NULL);
    p1 = (char *)dst;
    p2 = (const char *)src;
    while (n-- > 0)
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    return (dst);
}

char    *ft_strdup(const char *s1)
{
    char    *copy;
    size_t    len;

    len = ft_strlen(s1) + 1;
    copy = malloc(len);
    if (!copy)
        return (NULL);
    ft_memcpy(copy, s1, len);
    return (copy);
}