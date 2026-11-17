# sesion-14a

## apuntes sesión

## 🔀 Diagramas de flujo

<details>
<summary><b>Mapa de flujo: experiencia de usuario</b></summary>

```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Inicio<br/>sistema apagado]) --> B{"¿Mantiene el botón de<br/>encendido por 2 segundos?"}
    B -- No --> A
    B -- Sí --> C["Se enciende el sistema<br/>y ve el menú de personajes"]

    C --> D["Gira la perilla 1 para elegir<br/>Giuliano · Ana María · Nicole · Sofía"]
    D --> E{"¿Presiona el botón<br/>selector una vez?"}
    E -- No --> D
    E -- Sí --> F["Selecciona el personaje<br/>y empieza el audio de la primera etapa"]

    F --> G["Ve en la pantalla la etapa<br/>y el rango de edad"]
    G --> H["Gira la perilla 1 para avanzar<br/>o retroceder en la línea de tiempo"]
    H --> I["Activa o apaga las capas<br/>Casa · Calle · Escuela/Trabajo · País"]
    I --> J["Gira la perilla 2<br/>para subir o bajar el volumen"]
    J --> K{"¿El audio está borroso?<br/>Giuliano en vejez<br/>Ana María al final de la adultez"}
    K -- Sí --> L{"¿Presiona el<br/>botón recordar?"}
    L -- Sí --> M["Recupera la nitidez<br/>del recuerdo"]
    L -- No --> N
    K -- No --> N
    M --> N{"¿Mantiene el botón<br/>selector por 2 segundos?"}

    N -- Sí --> C
    N -- No --> O{"¿Mantiene el botón de<br/>encendido por 2 segundos?"}
    O -- Sí --> A
    O -- No --> P{"¿Terminó el audio de la<br/>última etapa del personaje?"}
    P -- No --> G
    P -- Sí --> Q{"¿El personaje<br/>es Giuliano?"}
    Q -- Sí --> R["Latido lento, silencio<br/>y vuelve el llanto de guagua"]
    R --> F
    Q -- No --> S["El audio queda en silencio<br/>hasta que mueva la perilla 1"]
    S --> G

    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef accion fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef menu fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;

    class A inicio;
    class B,E,K,L,N,O,P,Q decision;
    class D,F,G,H,I,J,M accion;
    class C,R,S menu;

    linkStyle default stroke:#2E7D32,stroke-width:2px;
```

</details>

<details>
<summary><b>Mapa de flujo: máquina</b></summary>

```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Alimentación del sistema]) --> B["Inicializar pantalla OLED,<br/>reproductor MP3, botones y perillas<br/>estado = APAGADO"]
    B --> C{"¿Botón de encendido<br/>mantenido 2 s?"}
    C -- No --> C
    C -- Sí --> D["estado = MENÚ<br/>Mostrar personajes en pantalla"]

    D --> E["Leer perilla 1<br/>Dividir en 4 rangos<br/>Giuliano · Ana María · Nicole · Sofía"]
    E --> F{"¿Botón selector<br/>toque corto?"}
    F -- No --> E
    F -- Sí --> G["Confirmar personaje<br/>Cargar sus etapas y audios<br/>estado = REPRODUCIENDO"]

    G --> H["Leer perilla 1<br/>Dividir en 7 etapas"]
    H --> I{"¿El personaje tiene<br/>esa etapa?"}
    I -- No --> J["Detener audio<br/>Mostrar etapa sin audio"]
    I -- Sí --> K["Reproducir audio de la etapa<br/>Mostrar rango de edad y nombre"]
    J --> L
    K --> L["Leer perilla 2<br/>Ajustar volumen del reproductor"]

    L --> M["Leer botones 4 a 7<br/>Activar o desactivar capas<br/>Casa · Calle · Escuela/Trabajo · País"]
    M --> N{"¿Etapa con distorsión?<br/>Giuliano: vejez<br/>Ana María: final de adultez"}
    N -- Sí --> O["Aplicar distorsión al audio"]
    O --> P{"¿Botón recordar<br/>presionado?"}
    P -- Sí --> P2["Quitar distorsión<br/>Recuperar nitidez"]
    P -- No --> T
    P2 --> T
    N -- No --> T{"¿Botón de encendido<br/>toque corto?"}

    T -- Sí --> U["Pausar o reanudar audio"]
    T -- No --> V
    U --> V{"¿Botón selector<br/>mantenido 2 s?"}
    V -- Sí --> D
    V -- No --> W{"¿Botón de encendido<br/>mantenido 2 s?"}
    W -- Sí --> X["Detener audio<br/>Apagar pantalla<br/>estado = APAGADO"]
    X --> C
    W -- No --> Y{"¿Terminó el audio de<br/>la última etapa del personaje?"}

    Y -- No --> H
    Y -- Sí --> Z{"¿El personaje<br/>es Giuliano?"}
    Z -- Sí --> AA["Latido lento, silencio y llanto<br/>Reiniciar en la primera etapa"]
    AA --> K
    Z -- No --> AB["Mantener silencio<br/>Esperar que se mueva la perilla 1"]
    AB --> H

    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef menu fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;

    class A inicio;
    class C,F,I,N,P,T,V,W,Y,Z decision;
    class B,E,G,H,J,K,L,M,O,P2,U proceso;
    class D,X,AA,AB menu;

    linkStyle default stroke:#2E7D32,stroke-width:2px;
```

</details>

<details>
<summary><b>Diagrama de flujo: botones</b></summary>

**Botones 1 y 2 (encendido y selector):** ambos distinguen entre un toque corto y una pulsación larga de 2 segundos.

```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B{"¿La persona está<br/>presionando el botón?"}

    B -- Sí --> C{"¿Ya estaba presionado<br/>en el ciclo anterior?"}
    C -- No --> D["Anota la hora de inicio<br/>Estado: estaSiendoPresionado"]
    C -- Sí --> E{"¿Pasaron 2 segundos<br/>desde el inicio?"}
    E -- No --> F["Sigue esperando<br/>Estado: estaSiendoPresionado"]
    E -- Sí --> G["Avisa: PULSACIÓN LARGA<br/>Botón 1: ENCENDER o APAGAR el sistema<br/>Botón 2: REINICIAR y volver al menú"]
    G --> H["Marca la pulsación como usada<br/>para no repetir el aviso"]

    B -- No --> I{"¿Estaba presionado<br/>en el ciclo anterior?"}
    I -- Sí --> J{"¿La pulsación ya fue<br/>usada como larga?"}
    J -- No --> K["Avisa: TOQUE CORTO<br/>Botón 1: INICIAR o PAUSAR el audio<br/>Botón 2: SELECCIONAR personaje"]
    J -- Sí --> L["No avisa nada más"]
    K --> M["Estado: noPresionado"]
    L --> M
    I -- No --> M

    D --> A
    F --> A
    H --> A
    M --> A

    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;

    class A inicio;
    class B,C,E,I,J decision;
    class D,F,H,L,M proceso;
    class G,K aviso;

    linkStyle default stroke:#2E7D32,stroke-width:2px;
```

**Botón 3 (recordar):** recupera la nitidez solo cuando el audio está distorsionado.

```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B{"¿La persona está<br/>presionando el botón?"}

    B -- Sí --> C{"¿Ya estaba presionado<br/>en el ciclo anterior?"}
    C -- Sí --> D["Estado: estaSiendoPresionado<br/>No avisa nada nuevo<br/>(no se repite sola)"]
    C -- No --> E["Avisa de inmediato:<br/>quiere recordar"]
    E --> F["Estado: estaSiendoPresionado"]

    B -- No --> G{"¿Estaba presionado<br/>en el ciclo anterior?"}
    G -- Sí --> H["Estado: soltado"]
    H --> I["Estado: noPresionado"]
    G -- No --> I

    D --> A
    F --> A
    I --> A

    E --> M{"Programa principal:<br/>¿el audio está distorsionado?"}
    M -- No --> P(["No pasa nada<br/>El audio ya es nítido"])
    M -- Sí --> O(["Se recupera la nitidez<br/>del recuerdo"])

    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;

    class A,O,P inicio;
    class B,C,G,M decision;
    class D,F,H,I proceso;
    class E aviso;

    linkStyle default stroke:#2E7D32,stroke-width:2px;
```

**Botones 4 a 7 (capas):** cada botón activa su capa con un toque y la desactiva con el siguiente.

```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B{"¿La persona está<br/>presionando el botón?"}

    B -- Sí --> C{"¿Ya estaba presionado<br/>en el ciclo anterior?"}
    C -- Sí --> D["Estado: estaSiendoPresionado<br/>No avisa nada nuevo"]
    C -- No --> E["Avisa de inmediato:<br/>cambió la capa"]
    E --> F["Estado: estaSiendoPresionado"]

    B -- No --> G["Estado: noPresionado"]

    D --> A
    F --> A
    G --> A

    E --> H{"Programa principal:<br/>¿la capa estaba activa?"}
    H -- No --> I(["ACTIVA la capa<br/>Botón 4: Casa · Botón 5: Calle<br/>Botón 6: Escuela/Trabajo · Botón 7: País"])
    H -- Sí --> J(["DESACTIVA la capa<br/>El resto del audio sigue sonando"])

    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;

    class A,I,J inicio;
    class B,C,H decision;
    class D,F,G proceso;
    class E aviso;

    linkStyle default stroke:#2E7D32,stroke-width:2px;
```

</details>

<details>
<summary><b>Diagrama de flujo: perillas</b></summary>

**Perilla 1 (personajes y línea de tiempo):** su función depende del estado del sistema.

```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B["Leer valor analógico<br/>de la perilla<br/>0 a 4095"]
    B --> C{"¿En qué estado<br/>está el sistema?"}

    C -- MENÚ --> D["Dividir el recorrido<br/>en 4 rangos<br/>de izquierda a derecha"]
    D --> E["Giuliano · Ana María<br/>Nicole · Sofía"]
    E --> F{"¿Cambió el personaje<br/>respecto al ciclo anterior?"}
    F -- Sí --> G(["Avisa: nuevo personaje<br/>Se actualiza el menú"])
    F -- No --> H(["No avisa nada nuevo"])

    C -- REPRODUCIENDO --> I["Dividir el recorrido<br/>en 7 etapas<br/>como una línea de tiempo"]
    I --> J{"¿El personaje tiene<br/>esa etapa?"}
    J -- Sí --> K(["Avisa: nueva etapa<br/>Suena el audio y se muestra<br/>la edad y el nombre de la etapa"])
    J -- No --> L(["Avisa: etapa sin audio<br/>Se detiene el audio<br/>en las etapas que restan"])

    G --> A
    H --> A
    K --> A
    L --> A

    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;

    class A inicio;
    class C,F,J decision;
    class B,D,E,I proceso;
    class G,H,K,L aviso;

    linkStyle default stroke:#2E7D32,stroke-width:2px;
```

**Perilla 2 (volumen):** funciona igual que el volumen de una radio.

```mermaid
%%{init: {'theme':'base','themeVariables':{'fontFamily':'Arial','lineColor':'#2E7D32','primaryTextColor':'#0B3C5D'}}}%%
flowchart TD
    A([Ciclo principal llama a update]) --> B["Leer valor analógico<br/>de la perilla<br/>0 a 4095"]
    B --> C["Convertir el valor a volumen<br/>Todo a la izquierda: 0 (silencio)<br/>Todo a la derecha: 30 (máximo)"]
    C --> D{"¿El volumen cambió respecto<br/>al ciclo anterior?"}
    D -- Sí --> E(["Avisa: nuevo volumen<br/>El reproductor sube o baja el sonido"])
    D -- No --> F(["No avisa nada nuevo"])
    E --> A
    F --> A

    classDef inicio fill:#0B3C5D,stroke:#2E7D32,stroke-width:2px,color:#FFF9DB;
    classDef decision fill:#FFD60A,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef proceso fill:#C8E6C9,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;
    classDef aviso fill:#BFE3F5,stroke:#0B3C5D,stroke-width:2px,color:#0B3C5D;

    class A inicio;
    class D decision;
    class B,C proceso;
    class E,F aviso;

    linkStyle default stroke:#2E7D32,stroke-width:2px;
```

</details>
