/*
 * file:     comm_player_p17.c
 * unit:     yes
 * function: func_021690E0, func_021690F0, func_02169100, func_02169110, func_02169120, func_02169138
 * address:  0x021690E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_0203F524 0x0203F524 arm
 *   func_02008BD0  0x02008BD0  thumb
 */
#include "../../matched/include/Obj17737.h"
#include "../../matched/include/Obj17738.h"
#include "../../matched/include/Obj17739.h"
#include "../../matched/include/Obj17740.h"

struct Big;
struct Sub02008AECSession;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern u64 func_0203F524(void);
extern int func_02008BD0(const struct Sub02008AECSession *s);
int func_021690E0(int a0);
int func_021690F0(int a0);
int func_02169100(int a0);
int func_02169110(int a0);
void func_02169120(void *p);
int func_02169138(int a0);


int func_021690E0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690E6:
    s = func_02008B14(big);
loc_021690EA:
a0 = ((struct Obj17737 *)s)->fC;
    return a0;}


int func_021690F0(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_021690F6:
    s = func_02008B14(big);
loc_021690FA:
a0 = ((struct Obj17738 *)s)->f10;
    return a0;}


int func_02169100(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_02169106:
    s = func_02008B14(big);
loc_0216910A:
a0 = ((struct Obj17739 *)s)->f14;
    return a0;}


int func_02169110(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_02169116:
    s = func_02008B14(big);
loc_0216911A:
a0 = ((struct Obj17740 *)s)->f18;
    return a0;}

void func_02169120(void *p) { char *q = (char *)func_02008B14(func_02012EBC(p)); *(u64 *)(q + 0x2c) = func_0203F524(); }


int func_02169138(int a0)
{
    void *big;
    struct Sub02008AECSession *s;


    big = func_02012EBC((struct Big *)a0);
loc_0216913E:
    s = func_02008B14(big);
loc_02169142:
    a0 = func_02008BD0(s);
loc_02169146:
    return a0;}
