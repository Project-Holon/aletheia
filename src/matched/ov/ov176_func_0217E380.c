/*
 * function: func_0217E380,func_0217E40C
 * unit: yes
 * address: 0x0217E380
 * packet: pkt_ov176_0217E380
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: two alignment bytes follow func_0217E40C
 * symbols:
 *   func_02157E78 0x02157E78 thumb ov010
 *   func_02157E34 0x02157E34 thumb ov010
 *   func_02157E6C 0x02157E6C thumb ov010
 *   func_02157E8C 0x02157E8C thumb ov010
 *   func_0203D210 0x0203D210 arm
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02157E78(u8 *p);
extern int func_02157E34(void *p);
extern unsigned char func_02157E6C(char *p);
extern int func_02157E8C(int a0);
extern u32 func_0203D210(void);
int func_0217E380(char *p)
{
    if (*(void **)(p + 0x1018))
        func_02157E78(*(void **)(p + 0x1018));
    switch (*(unsigned *)p) {
    case 0:
        func_02157E34(*(void **)(p + 0x1018));
        (*(unsigned *)p)++;
        break;
    case 1:
        *(int *)(p + 0x101C) = func_02157E6C(*(void **)(p + 0x1018));
        if (*(int *)(p + 0x101C))
            (*(unsigned *)p)++;
        break;
    case 2:
        func_02157E8C((int)(*(void **)(p + 0x1018)));
        *(void **)(p + 0x1018) = 0;
        (*(unsigned *)p)++;
        break;
    case 3:
        if (func_0203D210()) {
            switch (*(int *)(p + 0x101C)) {
            case 1: return 1;
            case 3: return 3;
            case 2: break;
            }
            return 2;
        }
        break;
    }
    return 0;
}
void func_0217E40C(int *p) { *p = 0; }
