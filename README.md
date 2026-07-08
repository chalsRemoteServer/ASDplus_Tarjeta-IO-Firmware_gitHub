<h1 align="center">
  <a href="https://github.com/tu-usuario/asdplus-io-board">
    <img alt="I/O Board ASD+" src="https://www.gracida.com/wp-content/uploads/2023/12/gracida-min-300x100.png" height="78">
  </a>
  <br>I/O Board para Equipo ASD+<br>
</h1>

<h4 align="center">
  Placa de expansión de Entradas/Salidas diseñada en KiCad
</h4>

<p align="center">
  <a href="https://github.com/tu-usuario/asdplus-io-board">
    <img src="https://img.shields.io/badge/KiCad-6.0%2B-FF6B6B?style=flat-square&logo=kicad&logoColor=white"
      alt="KiCad" />
  </a>

  <a href="https://github.com/tu-usuario/asdplus-io-board/blob/main/LICENSE">
    <img src="https://img.shields.io/badge/License-MIT-00D1B2?style=flat-square"
      alt="License" />
  </a>

  <a href="https://github.com/tu-usuario/asdplus-io-board/actions">
    <img src="https://img.shields.io/badge/PCB-Ready%20to%20Fab-4ECDC4?style=flat-square"
      alt="Status" />
  </a>
</p>

<p align="center">
  <a href="https://github.com/tu-usuario/asdplus-io-board/actions?query=workflow%3A%22Release%22">
    <img src="https://img.shields.io/badge/Release-v1.0-blue?style=flat-square"
      alt="Release" />
  </a>
  
  <a href="https://github.com/tu-usuario/asdplus-io-board">
    <img src="https://img.shields.io/badge/version-1.0.0-green?style=flat-square"
      alt="Version" />
  </a>

  <a href="https://github.com/tu-usuario/asdplus-io-board">
    <img src="https://img.shields.io/badge/status-active-success?style=flat-square"
      alt="Status" />
  </a>
</p>

<p align="center">Interfaz robusta para conectar sensores y actuadores al mundo físico del sistema ASD+.</p>

<p align="center">
  <a href="https://github.com/tu-usuario/asdplus-io-board">Repositorio</a> |
  <a href="#características">Características</a> |
  <a href="#instalación">Instalación</a> |
  <a href="#uso">Uso</a> |
  <a href="#fabricación">Fabricación</a> |
  <a href="#contribuir">Contribuir</a>
</p>
<p align="center">
  <a href="https://github.com/tu-usuario/asdplus-io-board/blob/main/CODE_OF_CONDUCT.md">Código de Conducta</a> | 
  <a href="#ayuda">¿Ayuda?</a> |
  <a href="#aviso-legal">Aviso Legal</a>
</p>
<p align="center">
  <a href="#equipo-asd">Equipo ASD+</a>
</p>
<p align="center">
  <img alt="I/O Board ASD+" src="https://raw.githubusercontent.com/adafruit/Adafruit-Feather-PCB/master/Feather_3D.png" style="max-height: 500px;max-width: 100%;height: auto;width: auto;object-fit: contain;" />
</p>

## Características

- **Entradas (Inputs)**
  - 4x Digitales - Ópticamente aisladas, 5-24V
  - 2x Analógicas - 0-10V / 4-20mA seleccionable
  - 2x Interrupción - Entradas rápidas para encoders
- **Salidas (Outputs)**
  - 4x Relés - Contactos NA/NC, 2A máx
  - 4x Digitales - Salidas por transistor MOSFET
  - 2x PWM - Señales moduladas para control fino
- **Comunicación**
  - Bus ASD+ - Conector dedicado de 10 pines
  - I2C / SPI - Headers de expansión
- **Alimentación**
  - 12V - 24V DC con protección
  - Temperatura de operación: -20°C a +85°C
- **Software**
  - KiCad 6.0 / 7.0
  - PCB de 2 capas - FR4 estándar

> Sigue este repositorio para mantenerte actualizado sobre nuevas versiones, mejoras y correcciones.

## Instalación

Para usar este diseño necesitas tener [`KiCad`](https://www.kicad.org/) instalado. El proyecto ha sido probado con KiCad versiones 6.0 y superiores.
