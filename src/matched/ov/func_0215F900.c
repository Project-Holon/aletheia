/*
 * function: func_0215F900
 * address:  0x0215F900
 * packet:   pkt_0215F900
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three arm9 size reads on the record's handle, cached at three fields.
 *
 * symbols:
 *   func_02012934   0x02012934  thumb
 *   func_02012944   0x02012944  thumb
 *   func_02012FCC   0x02012FCC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern int func_02012944(void *);
extern int func_02012FCC(void *);

void func_0215F900(void *a0)
{
    char *p = (char *)a0;

    *(void **)(p + 0x1C) = func_02012934(*(void **)(p + 4));
    *(int *)(p + 0x20) = func_02012944(*(void **)(p + 4));
    *(int *)(p + 0x24) = func_02012FCC(*(void **)(p + 4));
}

