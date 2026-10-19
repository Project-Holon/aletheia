# One link of ARM9, ITCM and every overlay

`tools/onelink.py` links the ARM9 static module, the ITCM autoload and all 180 code overlays in one
`mwldarm` run with one generated linker command file. It reuses the objects that `tools/gamelink.py`
builds (data mode); it changes neither `gamelink.py` nor `romlink.py`.

    python tools/onelink.py capture [--jobs N] [REGION ...]   # about 2.5 minutes, 182 regions
    python tools/onelink.py link    [--only REGION ...]       # about 5 minutes (python) + 20 s (mwldarm)
    python tools/onelink.py compare [--only REGION ...]

Output is in `build/onelink/` (not tracked): `regions/<region>/` (captured inputs), `link/`
(`onelink.lcf`, `onelink.elf`, merged objects, `link.log`).

## Result (this wave)

One `mwldarm` run: 182 regions, 2334 objects, 2833 memory regions, 24.7 KB command line, 21 s.
Every output section of the one link, compared byte for byte with the per-region link of the same
region: 182 of 182 regions identical (code, data, bss stand-ins excluded as in the region links,
veneers included). Against the extract: 181 of 182; the ARM9 static module differs in 2 bytes
(`msl_ansi_fp`, 0x0209756C and neighbour), and so does its own per-region link, so that is a state
of the ARM9 sources at capture time, not an effect of the one link.

Not covered: nothing was skipped; overlay 230 links its decrypted view as in `gamelink.py`.

## How the .lcf is built (NitroSDK template shape)

The template (`TwlSDK .../specfiles/*.lcf.template`) declares one MEMORY region per overlay with
the flags `(RWXO)` and the same ORIGIN for overlays that share an address range, and one output
section per overlay. mwldarm accepts overlapping `O` regions and links each at its own origin; no
overlay ID table or size limit got in the way. `onelink.py` keeps gamelink's finer structure
(one region per file piece, per data segment, per gap) and gives every overlay region the `O`
flag. ARM9 static and ITCM regions are plain regions.

Per region the command file of its own run is parsed and renamed (prefix `A9`, `IT`, `oNNN` on
objects, memory regions and output sections). What had to be reconciled because 182 command
files now share one namespace:

1. Companion anchors (`z*`, address 0x0E000000 and up) and parked dead data (0x0F000000 and up) are
   moved to a distinct band per region.
2. `SINIT_START`/`SINIT_END` and other symbols defined inside a section body get a per-region name.
3. Absolute symbol assignments: dropped when an object of the link defines the same name at the same
   address; renamed per region when another region or object gives the name a different value.
4. A global function name defined by objects of two regions (an overlay copy of an ARM9 name, or two
   overlays): the overlay copies get `name__oNNN`.
5. Stubs. gamelink gives each callee outside the region a typed stub (`stubs.o`, section at the
   callee address). In the one link a callee in ARM9, ITCM or another overlay is a real
   definition, so the stub is replaced by a reference to it:
   - exact definition of that name at that address: used directly;
   - otherwise a new global alias `<stub name>__rNNN` is added to the object that holds the address
     (function start or entry inside a function, or a typed symbol in a gap object). One alias per
     call-site stub name keeps one veneer per call, which is what the original link produced
     (mwldarm shares veneers per symbol; with one shared name the call targets moved by one
     veneer and the first try differed in about 20 regions);
   - several overlays cover one address: the candidate whose function starts exactly there and has
     the same ARM or Thumb mapping is taken (a mid-function candidate of another overlay encoded
     BLX where the original has BL);
   - no region of the link holds the address (157 stubs: the limited-mode autoload at 0x027xxxxx and
     a few others): one typed stub object `xstubs.o` with one stub name per region and address
     (a name shared between regions made a different veneer layout in ARM9 and overlay 172), the
     ARM or Thumb type taken from the mapping symbol of the region that had the stub.

## Findings

- Identical: all code and data of ARM9, ITCM and 180 overlays, incl. veneers, alignment padding and
  data order, once the stub rules above are used.
- Differences met on the way (all fixed in `onelink.py`, none left): veneer sharing across call sites
  (BL targets shifted by one veneer), BL versus BLX where two overlays define a function at one
  address, Thumb versus ARM typing of the unresolved stubs (ARM9 lost 16 byte Thumb veneers),
  per-region veneers for the 0x027xxxxx stubs, absolute names that two regions mean differently,
  and a rename that matched `.text` inside a section list.
- The first working link printed "Segment ... have to begin at address aligned to 32" for the
  overlay data segments; the final link prints only the usual "No main entry point" warning, and
  the bytes were not affected by it.

## `romlink.py --onelink` (done)

    python tools/romlink.py --onelink [--recapture] [--jobs N]

Prints IDENTICAL, SHA-1 `26ad0b9967aa279c4a266ee69f52b9b2332399a5`, "per file: no file differs",
"image bytes inside the linked regions: 0". Steps:

1. Companions and pads, as `--relink` writes them (`datagen.py companions`, `arm9data.py`, the
   ITCM pads, the overlay 230 blobs), then `onelink.py capture`. Both are skipped when
   `build/onelink/capture.ok` is newer than every `src/game` file, every `layout` JSON file and the
   link tools. `--recapture` forces them.
2. `onelink.py link`. The result is cached: the key is the SHA-1 of every captured file of the 182
   regions (objects, region command files, region results) and of `onelink.py` and `gamelink.py`,
   stored in `build/onelink/link/key.txt`. An unchanged key skips stub resolution and mwldarm (under
   one second). `onelink.py link --force` links again.
3. `onelink.extract_images()` cuts each region from `onelink.elf` by section prefix (`A9_`, `IT_`,
   `oNNN_`), takes the `.bss` stand-in ranges from the extract image, and refuses a region with bytes
   in no section.
4. The rest is unchanged: overlay 230 encryption, autoload pieces, BLZ packing, `ndsrom.py build`,
   SHA-1 comparison.

The python part of `link` used to take about 5 minutes because it called `re.sub` once per rename
key and per section body (5.4 million calls, each compiling a pattern). It now builds one combined
pattern per region (`make_subst`): the link takes about 80 seconds without the cache, and the
`onelink.elf` it writes is byte-identical to the one of the slow version. Measured, cold: companions
150 s, capture 160 s, link 80 s, ROM steps about 2 minutes; warm capture and link: seconds.
