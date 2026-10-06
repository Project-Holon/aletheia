/*
 * function: func_021ECA6C
 * address: 0x021ECA6C
 * packet: pkt_ov170_021ECA6C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD908 0x021DD908 thumb ov170
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021EC060 0x021EC060 thumb ov170
 */
#include "../include/Obj06551.h"
#include "../include/Obj24017.h"
typedef unsigned int   u32;
extern int func_021DD908(char *p, u32 a);
extern unsigned func_021DD25C(void ***, unsigned short, int, unsigned, unsigned);
extern void func_021EC060(char *p, unsigned i, int b);
#define WORK(p) (*(char **)((p) + 0x2C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
void func_021ECA6C(unsigned char *p, int flag, int i, unsigned end, int mode)
{
    if (mode == 1) {
        if (((struct Obj24017 *)(*(char * *)&((struct Obj06551 *)p)->f0))->f24 == 5) {
            for (; i < end; i++) {
                if (func_021DD908((char *)p, i) == 1 && func_021DD25C((void ***)p, i, p[0x14], 0x4C, 0) == 0)
                    func_021EC060(WORK(p), WIN(p, i), 0);
                else
                    func_021EC060(WORK(p), WIN(p, i), 1);
            }
        } else {
            for (; i < end; i++) {
                if (func_021DD25C((void ***)p, i, p[0x14], 6, 0) == 0)
                    func_021EC060(WORK(p), WIN(p, i), 1);
                else
                    func_021EC060(WORK(p), WIN(p, i), 0);
            }
        }
    } else {
        for (; i < end; i++)
            func_021EC060(WORK(p), WIN(p, i), flag);
    }
}
