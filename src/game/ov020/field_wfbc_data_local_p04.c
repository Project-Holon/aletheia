/*
 * file:     field_wfbc_data_local_p04.c
 * unit:     yes
 * function: func_021861F4, func_0218625C, func_02186278
 * address:  0x021861F4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200855C  0x0200855C  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 *   func_021866F8  0x021866F8  thumb  ov020
 *   func_021861BC 0x021861BC thumb ov020
 *   func_02161ECC 0x02161ECC thumb ov010
 */
struct Sub0200852CObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

u8 func_0200855C(const struct Sub0200852CObj *obj);
u32 func_02008530(const struct Sub0200852CObj *obj);
int func_021584F4(int a, int b);
void func_021866F8(char *p);
extern int func_021861BC(unsigned short *);
extern int func_02161ECC(char *);
void func_021861F4(u16 *p, int x);
int func_0218625C(unsigned short *p);
int func_02186278(char *p,int which);


void func_021861F4(u16 *p, int x)
{
    int i;

    if (p[0] > 1)
        p[0] = 1;
    if (p[0] == 0 && p[1] != 2)
        p[1] = 2;
    if (p[0] == 1 && p[1] >= 2) {
        int r6 = func_0200855C((const struct Sub0200852CObj *)x);
        if (func_021584F4((u8)r6, func_02008530((const struct Sub0200852CObj *)x)) == 0x15)
            p[1] = 0;
        else
            p[1] = 1;
    }
    for (i = 0; i < 10; i++)
        func_021866F8((char *)p + 8 + i * 0x18);
}

int func_0218625C(unsigned short *p) { if (p[0]==0) return 0; if (func_021861BC(p)!=0) return 1; return 0; }

int func_02186278(char *p,int which) { char *q; int i; int count; if (which==0) q=p+8; else q=p+0xf8; count=0; for(i=0;i<10;i++) if(func_02161ECC(q+i*0x18)) count++; return count; }
