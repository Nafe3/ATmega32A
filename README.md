# ATmega32A introduction labs

[![CI](https://github.com/Nafe3/ATmega32A/actions/workflows/ci.yml/badge.svg)](https://github.com/Nafe3/ATmega32A/actions/workflows/ci.yml)

Archive of **AVR / ATmega32A** coursework completed during Eng. Assaf's **introduction to embedded systems** track (**ITI**). Each dated folder bundles schematics-facing code (`LCD`, `timers`, `DAC`, keypad assignments, motors, etc.).

## Layout

Historical naming (`DD-MM-YYYY_topic`) preserves classroom references. Inspect any folder README or source files for peripherals used that week.

## Build flow

Labs were developed with AVR toolchain + IDE tooling from the cohort (Atmel Studio / Microchip toolchain). Typical flow:

```bash
git clone https://github.com/Nafe3/ATmega32A.git
cd ATmega32A/<assignment-folder>
# open .cproject/.project metadata or Makefile from coursework
```

> Note: Scala appears in GitHub language stats due to tooling/metainfo inside Eclipse metadata — C/Assembly remain the authoring languages.

## CI

Workflow guarantees root README saturation + sanity directory presence representative of coursework depth.
