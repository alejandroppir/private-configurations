# Tutorial QMK

https://docs.qmk.fm/#/newbs_getting_started

## Descargas

Descargar qmk_msys.exe
Descargar qmk toolbox

## Configuraciones

```shell
qmk setup
qmk config user.keyboard=kprepublic/bm80v2_iso
qmk config user.keymap=alejandroppir
```

Abrir qmk toolbox como admin e instalar drivers

## Crear nuevo mapeo

En qmk msys

```shell
qmk new-keymap
```

Esto nos creará un nuevo mapeo con el nombre que hemos configurado
Pegar el fichero rules.mk dentro de bm80v2_iso

### Compilar

En la carpeta de bm80v2_iso

```shell
qmk compile -kb kprepublic/bm80v2_iso -km alejandroppir
```

## Flashear

Abrir qmk toolbox

Poner el teclado en modo flash (tecla utils, y escape)

Cargar el fichero.hex

Si nos da error de dfu-programmer, descargarlo y meterlo en %AppData%/Local/QMK/Toolbox https://github.com/dfu-programmer/dfu-programmer

Darle a Flash

Desenchufar y enchufar teclado (si no lo autoreconoce)

## Errores

Si no nos flashea, reiniciar pc
