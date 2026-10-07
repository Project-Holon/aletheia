/*
 * file:     unit_0217956C_p05.c
 * unit:     yes
 * function: func_0217A0D4, func_0217A120, func_0217A15C
 * address:  0x0217A0D4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082bcc  arm
 *   MI_CpuCopy8  0x02082D44  arm
 */
typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
int func_0217A15C(char *http, Buf *buf, int size);

static int DWCi_Http_AllocBuffer(char *http, char *buf, unsigned long size)
{
    void *(*alloc)(unsigned long, long) = *(void *(**)(unsigned long, long))(http + 0x1010);
    void *p;

    if (size == 0)
        return 0;

    p = alloc(0, size);
    *(void **)(buf + 0) = p;
    if (p == 0)
        return 0;

    *(void **)(buf + 4) = p;
    *(void **)(buf + 8) = (char *)p + size;
    *(unsigned long *)(buf + 0xc) = size;
    return 1;
}


static void DWCi_Http_FreeBuffer(char *http, char *buf)
{
    void (*free)(unsigned long, void *, long) = *(void (**)(unsigned long, void *, long))(http + 0x1014);

    if (*(void **)buf != 0) {
        free(0, *(void **)buf, 0);
    }
    MI_CpuFill8(buf, 0, 0x10);
}


/*
 * sdk:      DWCi_Http_ReallocBuffer (dwc_http.o)
 */
int func_0217A15C(char *http, Buf *buf, int size)
{
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
    char *newptr;

    alloc = *(void *(**)(unsigned long, long))(http + 0x1010);
    free = *(void (**)(unsigned long, void *, long))(http + 0x1014);
    if (size <= 0) {
        return 0;
    }
    newptr = alloc(0, buf->cap + size);
    if (newptr == 0) {
        return 0;
    }
    MI_CpuCopy8(buf->base, newptr, buf->cap);
    free(0, buf->base, 0);
    if (newptr == 0) {
        return 0;
    }
    buf->cur = buf->cur + (newptr - buf->base);
    buf->cap = buf->cap + size;
    buf->base = newptr;
    buf->end = newptr + buf->cap;
    return 1;
}
