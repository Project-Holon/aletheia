/*
 * function: func_021BDCB8
 * address: 0x021BDCB8
 * packet: pkt_ov172_021BDCB8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * 2026-10-05 (wave D5 lane 02): real extent of func_021BBA94 is 0x021BBA94..0x021BBE50 (956 bytes, pool 0x404, 0x14A,
 * d_021C7234 at 0x021BBE50). A first full draft is parked as src/pending/ov/ov172_func_021BBA94.c, DIFF, so this stays MATCH*.
 * note (2026-10-05, wD4 lane17): still MATCH*, only func_021BBA94 (ov172, no witness, no matched file) is unresolved; it needs its own ov172 file.
 * note 2026-10-04 wD2 lane01: still MATCH*. The only unresolved site is func_021BBA94 (+006C): its extent is larger than 021BBA94..021BBAD4 (64 bytes shown, stale inner label) and needs its own ov172 witness file. Not in lane 01; a lane that owns 021BBA94 closes this.
 * blocker: func_021BBA94 ov172 lacks an outside witness; larger body
 * extends past stale inner label 021BBAD4. No split frees the only call.
 * Extent remainder: zero alignment halfword at 021BDD6A.
 * symbols:
 *   func_021B8FB8 0x021B8FB8 thumb ov172
 *   func_021BBE5C 0x021BBE5C thumb ov172
 *   func_021BA8C4 0x021BA8C4 thumb ov172
 *   func_021B8CC8 0x021B8CC8 thumb ov172
 *   func_021BBA94 0x021BBA94 thumb ov172
 *   func_021BA2C4 0x021BA2C4 thumb ov172
 *   func_0202223C 0x0202223C thumb
 *   func_021B8084 0x021B8084 thumb ov172
 *   func_021B7578 0x021B7578 thumb ov172
 *   func_021B7B80 0x021B7B80 thumb ov172
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_021B8FB8(void *,char *);
extern void func_021BBE5C(void *,char *);
extern void func_021BA8C4(void *,char *);
extern void func_021B8CC8(void *,char *);
extern void func_021BBA94(void *,char *);
extern void func_021BA2C4(void *,char *);
extern void func_0202223C(int,int);
extern void func_021B8084(void *,char *);
extern void func_021B7578(void *,char *);
extern void func_021B7B80(void *,char *);
void func_021BDCB8(u8 *p)
{
    switch (*(u32 *)(p+8)) {
    case 1: func_021B8FB8(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBE5C(p,*(char **)(p+0x1f0)); break;
    case 3: func_021BA8C4(p,*(char **)(p+0x1ec)); break;
    }
    *(u32 *)(p+8)=*(u32 *)(p+12);
    switch (*(u32 *)(p+8)) {
    case 0: break;
    case 1: func_021B8CC8(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBA94(p,*(char **)(p+0x1f0)); break;
    case 3: func_021BA2C4(p,*(char **)(p+0x1ec)); break;
    case 5:
        func_0202223C(0,0);
        func_0202223C(1,0);
    case 4:
        func_021B8084(p,*(char **)(p+0x1e4));
        func_021B7578(p,*(char **)(p+0x1e0));
        func_021B7B80(p,*(char **)(p+0x1e0));
        break;
    }
}
