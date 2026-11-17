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
    K --> L["Leer

## encargos

## lectura
