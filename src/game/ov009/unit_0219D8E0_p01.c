/*
 * file:     unit_0219D8E0_p01.c
 * unit:     yes
 * function: func_0219D8E0, func_0219D8FC
 * address:  0x0219D8E0
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
 *   func_0219D5B0  0x0219D5B0  arm  ov009
 *   closesocket      0x0217eb2c  arm
 *   FIFOClear        0x0219d5b0  arm
 */
struct _SBServer {
    char pad[0x24];
    struct _SBServer *next;
};

struct _SBServerFIFO {
    struct _SBServer *first;
    struct _SBServer *last;
    int count;
};

struct _SBQueryEngine {
    int queryversion;
    int maxupdates;
    struct _SBServerFIFO pending;
    struct _SBServerFIFO active;
    int socket;
};

extern void func_0219D5B0(int *p);
extern int closesocket(int sock);
extern void FIFOClear(struct _SBServerFIFO *fifo);
void func_0219D8E0(char *p);
void SBEngineCleanup(struct _SBQueryEngine *engine);


/*
 * Prepares the two blocks inside the argument.
 */
void func_0219D8E0(char *p)
{
    func_0219D5B0((int *)(p + 0x14));
    func_0219D5B0((int *)(p + 8));
}


void SBEngineCleanup(struct _SBQueryEngine *engine)
{
    closesocket(engine->socket);
    engine->socket = -1;
    FIFOClear(&engine->active);
    FIFOClear(&engine->pending);
}
