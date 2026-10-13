/*
 * function: DOWSING_FindNextTarget
 * address:  0x021EFF48
 * packet:   pkt_ov033_021EFF48
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetHiddenItemTable 0x0216476C thumb ov010
 *   DOWSING_IsTargetAvailable 0x021EFEEC thumb ov033
 *   INTRUDE_GetNextOfferSpot 0x021CFB68 thumb ov021
 */

typedef struct {
    unsigned kind;
    unsigned a;
    unsigned b;
} Rec;

typedef struct {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned short h6;
    unsigned f8;
    unsigned short hc;
} T;

extern char *EVENTDATA_SYSTEM_GetHiddenItemTable(unsigned short *);
extern int DOWSING_IsTargetAvailable(char *p, int *q);
extern unsigned INTRUDE_GetNextOfferSpot(unsigned, unsigned *);

int DOWSING_FindNextTarget(T *p, unsigned *out, int mode)
{
    unsigned short cnt;
    unsigned idx;
    Rec rec;
    char *tbl;
    unsigned v;
    int found;

    found = 0;
    tbl = EVENTDATA_SYSTEM_GetHiddenItemTable(&cnt);
    idx = p->hc;
    if (mode == 0 || mode == 1) {
        while (p->h4 < cnt) {
            rec.kind = 1;
            rec.a = (unsigned)(tbl + p->h4 * 10);
            if (DOWSING_IsTargetAvailable((char *)p, (int *)(&rec))) {
                out[0] = rec.kind;
                out[1] = rec.a;
                found = 1;
            }
            p->h4++;
            if (found)
                return 1;
        }
    }
    if (mode == 0 || mode == 2) {
        v = INTRUDE_GetNextOfferSpot(p->f8, &idx);
        p->hc = idx;
        while (v != 0) {
            rec.b = v;
            rec.kind = 2;
            if (DOWSING_IsTargetAvailable((char *)p, (int *)(&rec))) {
                out[0] = rec.kind;
                out[2] = rec.b;
                found = 1;
            }
            if (found)
                return 1;
            v = INTRUDE_GetNextOfferSpot(p->f8, &idx);
            p->hc = idx;
        }
    }
    out[0] = 0;
    return 0;
}
