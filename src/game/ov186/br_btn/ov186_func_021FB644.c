/*
 * function: func_021FB644
 * address: 0x021FB644
 * packet: pkt_ov186_021FB644
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_022007F0 0x022007F0 data a4
 *   d_02200D38 0x02200D38 data a1
 */
#include "../../../matched/include/Obj03892.h"
#include "../../../matched/include/Obj14460.h"
typedef struct Record { unsigned short fields[12]; } Record;
typedef struct Descriptor { unsigned short count, unused; const Record *records; int unknown; } Descriptor;
extern const Descriptor d_022007F0[];
extern char d_02200D38[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021FB644(char *ctx)
{
    int i;
    unsigned count;
    const Record *templates;
    unsigned index;
    unsigned j;
    unsigned total = 0;
    int *config = *(int * *)&((struct Obj14460 *)ctx)->f0;
    char *record;
    for (i = 0; i < 12; i++) {
        count = d_022007F0[i].count;
        templates = d_022007F0[i].records;
        for (j = 0; j < count; j++) {
            record = ctx + total * 24;
            *(Record *)(record + 4) = templates[j];
            switch (((struct Obj03892 *)record)->f1A) {
            case 1: ((struct Obj03892 *)record)->f14 = config[0]; break;
            case 2: case 3: case 4:
                index = ((struct Obj03892 *)record)->f1A - 2;
                if (index >= 4) func_02034714(d_02200D38, 0, d_02200D38);
                ((struct Obj03892 *)record)->f14 = config[index + 1];
                if (((struct Obj03892 *)record)->f14) ((struct Obj03892 *)record)->fA = 26;
                break;
            case 5: ((struct Obj03892 *)record)->f14 = config[20]; break;
            case 0: default: ((struct Obj03892 *)record)->f14 = 1; break;
            }
            total++;
        }
    }
}
