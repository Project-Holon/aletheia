/*
 * function: gsDebugVaList
 * address:  0x0217D19C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gsDebugVaList: the filtering dispatcher behind gsDebugFormat
 * (gsDebugFormat).  Lazily initialise the debug lock, take it, test the
 * category/type level byte and dispatch to the registered callback (or the
 * default va_list printer), then release the lock.
 *
 * The callback and the init flag are one object at 0x021AD000 (the flag is
 * read as [base,#4]); declaring them as a struct keeps that single pool
 * relocation.  The level table at 0x021AD020 is indexed [cat][type] with a
 * 5-byte row stride.
 *
 * symbols:
 *   gsiInitializeCriticalSection  0x0217F0FC  arm  ov009
 *   gsiEnterCriticalSection  0x0217F108  arm  ov009
 *   gsiLeaveCriticalSection  0x0217F114  arm  ov009
 *   gsiDebugCallback  0x0217D188  arm  ov009
 *   gGsDebugState     0x021AD000  data
 *   gGsDebugCriticalSection     0x021AD008  data
 *   gGsDebugEnabled     0x021AD020  data
 */

typedef char *va_list;

typedef struct {
    void (*callback)(int, int, int, const char *, va_list);
    int initialized;
} GSIDebugState;

extern void gsiInitializeCriticalSection(void *mutex);
extern void gsiEnterCriticalSection(void *mutex);
extern void gsiLeaveCriticalSection(void *mutex);
extern void gsiDebugCallback(int a, int b, int c, int d, int e);
extern GSIDebugState gGsDebugState;
extern int gGsDebugCriticalSection[];
extern unsigned char gGsDebugEnabled[][5];

void gsDebugVaList(int cat, int type, int level, const char *fmt, va_list args)
{
    unsigned char enabled;

    if (gGsDebugState.initialized == 0) {
        gGsDebugState.initialized = 1;
        gsiInitializeCriticalSection(gGsDebugCriticalSection);
    }
    gsiEnterCriticalSection(gGsDebugCriticalSection);
    enabled = gGsDebugEnabled[cat][type];
    if (enabled & level) {
        if (gGsDebugState.callback != 0)
            gGsDebugState.callback(cat, type, level, fmt, args);
        else
            gsiDebugCallback(cat, type, level, (int)fmt, (int)args);
    }
    gsiLeaveCriticalSection(gGsDebugCriticalSection);
}
