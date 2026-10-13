# Progress report for decomp.dev

decomp.dev shows the progress of a decompilation from an objdiff report that a
GitHub Actions run uploads. This project makes that report locally and commits
it, because CI has no ROM.

## What the report is

`progress/report.json` is the `Report` message of objdiff's
`objdiff-core/protos/report.proto` (encounter/objdiff), in protobuf JSON as
objdiff writes it:

- field names are the proto names (`total_code`, `matched_functions`);
- 64-bit integers (`total_code`, `matched_code`, `complete_code`, `size`,
  `virtual_address`) are JSON strings;
- fields at their default value are left out;
- `version` is 2. decomp.dev migrates older versions, and a version 1 report
  gets its unit counts added a second time.

The figures come from `tools/linkstats.py`:

| measure | rule |
|---|---|
| `total_code`, `total_functions` | every non-veneer function of the region listings, sized by its instruction bytes (linkstats rule D) |
| `matched_code`, `matched_functions` | functions with an EXACT or EXACT* match record in `layout/matched/`, or in a unit whose bytes came out identical |
| `complete_code`, `complete_units` | units that linkstats counts as linked (rule L) |
| `total_units` | top-level `src/game` source files (linkstats rule U) |

There is one unit per `src/game` source file, named `<region>/<stem>`, with its
functions (`fuzzy_match_percent` 100 or 0, `metadata.virtual_address`). Code that
no unit covers is in the units `<region>/_no_unit_game` and
`<region>/_no_unit_sdk` (`auto_generated`, not counted in `total_units`). The
categories are `game` and `sdk`: a unit is `sdk` when most of its code bytes are
SDK functions. Each category is the sum of its units.

The file holds names, sizes, addresses and percentages. It holds no ROM bytes.

## Refresh the report

Run this at each integration commit, after the matching and link checks:

    python tools/progress_report.py

It runs linkstats first (only regions with changed sources are linked again),
then writes `progress/report.json` and prints the headline figures. Commit the
file with the wave. The output is deterministic: the file changes only when a
figure changes.

Options:

- `--no-relink` uses `build/linkstats/cache.json` as it is (fast);
- `--check` exits 1 when the committed file is out of date;
- `--out PATH` writes somewhere else.

## CI

`.github/workflows/progress.yml` runs on each push to `main` (and by hand). It
needs no secrets and no ROM. It:

1. parses the committed report with `objdiff-cli report changes` (objdiff
   v3.8.2), so a malformed report fails the run;
2. uploads `progress/report.json` as the artifact `IRBO_report`.

decomp.dev reads the push runs of the default branch. It takes an artifact
whose name matches `<version>_report` and reads the file `report.json` in it.
The version is `IRBO`, the game code of Pokemon Black (USA, Europe).

## Launch steps

1. Make the repository public. decomp.dev reads public repositories only.
2. Push one commit to `main` after the repository is public, so that a
   `progress` run with an `IRBO_report` artifact exists. Check the run on the
   Actions tab.
3. Sign in on https://decomp.dev with GitHub.
4. Open https://decomp.dev/manage/new and add `Project-Holon/aletheia`:
   - name: aletheia (short name as you like);
   - platform: Nintendo DS;
   - decomp.dev finds the workflow with report artifacts. If it does not, set
     the workflow ID to `progress.yml` on the project manage page.
   - default version: `IRBO`.
5. Optional: install the decomp.dev GitHub app on the repository. Then each
   push is picked up at once (without it, decomp.dev polls), and the manage page
   can turn on pull request comments.
6. Optional: on the manage page, use "refresh" to load the reports of earlier
   runs.
7. Add badges to the READMEs. decomp.dev serves a shield for any measure:

       ![Code](https://decomp.dev/Project-Holon/aletheia.svg?mode=shield&measure=code&label=Code)
       ![Linked](https://decomp.dev/Project-Holon/aletheia.svg?mode=shield&measure=complete_code&label=Linked)
       ![Functions](https://decomp.dev/Project-Holon/aletheia.svg?mode=shield&measure=functions&label=Functions)

   Other measures: `matched_code_bytes`, `complete_units`,
   `complete_units_percent`. Add `&category=game` or `&category=sdk` for one
   category. The same URL with `.json` in place of `.svg` is a shields.io
   endpoint (`https://img.shields.io/endpoint?url=...`, URL-encoded).

## Check the format by hand

objdiff-cli can parse a report:

    objdiff-cli report changes progress/report.json progress/report.json

A run that ends without an error and prints the measures means objdiff (and so
decomp.dev, which uses objdiff-core to read reports) accepts the file.
