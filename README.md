<h4 align="center">📜 2024 Techeer Winter BootCamp K team 📜</h1>
<h1 align="center">🕵️ AILIBI 🕵️</h1>
<div align="center"> 
<h3><b> AI-based detective simulation game </b></h3><br>
<img width="1503" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/main.png" alt="대표 이미지">
<h3><b>AI+ALIBI(현재 부재 증명)= AILIBI</b></h3>

<br>

</div>
<br><br>



# 📖 Table of contents
* [Introduction](#-introduction)
* [Demo](#-demo)
* [API](#-api)
* [System Architecture](#-system-architecture)
* [ERD](#-erd)
* [Tech Stack](#-tech-stack)
* [Monitoring](#-monitoring)
* [How to start](#-how-to-start)
* [Directory Structure](#-directory-structure)
* [Team Members](#-team-members)

<br>

# 📣 Introduction
### URL
> 🗝️ [AILIBI](https://AILIBI.click) 

### Medium
> 🔎 [AILIBI Medium](https://medium.com) &nbsp;

<br>

- **AI+ALIBl(현재부재증명)=AILIBI**
- **AI 기반 탐정 시뮬레이션**
- **1인용 두뇌게임**
- **사용자가 사건 종류,장소,시간을 입력하면 AI(GPT-4)가 시나리오,용의자,증거를 생성한다**
- **사용자는 시나리오의 탐정이 되어 용의자를 심문하고 증거를 탐색한다**
- **진범은 찾아내면 승리한다**

<br>

# 🕺🏻 Demo
### 로그인 페이지 및 시작 페이지
> AILIBI 게임에 대한 간략한 설명을 담고 있습니다.
<img align="center" width="1000" alt="Onboarding" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/main.png">
<img align="center" width="1000" alt="Onboarding" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/login.png">


### 메인 페이지
> 현재까지 진행했던 히스토리 페이지 및 새로운 시나리오를 생성하는 시나리오 페이지로 이동이 가능합니다
<br>
<img align="center" width="1000" alt="Login & Sign up" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/mainPage.png">

<br>

### 시나리오 생성 페이지
> 플레이어가 탐정 스토리의 주요 배경과 사건을 설정하는 페이지입니다..<br>
> 사건의 종류,시간,장소 등을 선택할 수 있습니다.
<br>
<img align="center" width="1000" alt="Login & Sign up" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/make.png">

<br>

### 히스토리 페이지
> 플레이어가 이전에 해결했던 사건들을 확인할 수 있는 기록 페이지입니다.<br>
> 사건별 결과와 세부 정보를 조회할 수 있습니다.
<br>
<img align="center" width="1000" alt="" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/history.png">

<br>

### 로딩 페이지 및 미니게임
> 게임이 로드되는 동안 플레이어가 즐길 수 있는 간단한 미니게임이 포함된 페이지입니다.<br>
> 대기 시간을 줄이고 몰입감을 높이는 역할을 합니다.
<br>
<img align="center" width="1000" alt="" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/loading.png">
<img align="center" width="1000" alt="" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/minigame.png">
<br>

### 플레이 페이지
> 플레이어가 사건을 해결하며 진행하는 메인 게임 화면입니다.<br>
> 증거를 조하고, 용의자를 심문하며 사건의 진실을 추적합니다.
<br>
<img align="center" width="1000" alt="" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/play.png">

<br>
  
### 용의자 및 증거 페이지
> 주요 용의자들의 프로필, 알리바이, 행동 기록 등을 확인할 수 있는 페이지입니다.<br>
> 발견된 증거를 정리하고 분석하여 사건 해결에 활용합니다.
<br>
<img align="center" width="1000" alt="" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/">

<br>

### 용의자 채팅 페이지
> AI 기반으로 용의자와 실시간으로 대화하며 단서를 수집하는 페이지입니다.<br>
> TTS로 생성된 꿀보이스로 자유로운 대화가 가능합니다.
<br>
<img align="center" width="1000" alt="" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/">

<br>

### 추리 노트 팝업
> 플레이어가 정리한 사건의 단서, 용의자 관계도, 메모 등을 빠르게 볼 수 있는 팝업입니다.<br>
>추리를 위한 모든 정보를 한눈에 확인할 수 있습니다.
<br>
<img align="center" width="1000" alt="" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/">

<br>

### 결과 페이지
> 사건이 해결된 이후의 페이지로, 사건의 전개와 해결 과정을 요약합니다.<br>
> 플레이어의 선택에 따라 달라지는 결과 페이지와 크레딧 화면을 볼 수 있습니다
<br>
<img align="center" width="1000" alt="" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/">




<br>

# 📗 API
<img width="1503" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/API.png" alt="API 이미지">



<br><br>

# 🛠 ️System Architecture <a name="-system-architecture"></a>
<div align="center">
  <img align="center" width="1000" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/System.png">
</div>
<br><br>

# 🔑 ERD
<div align="center">
  <img width="1000" src="https://raw.githubusercontent.com/ksm0520/practice/main/images/erd.png">
</div>
<br><br>

# 💻 Tech Stack

<div align="center">
  <table>
    <tr>
      <th>Field</th>
      <th>Technology of Use</th>
    </tr>
    <tr>
      <td><b>Frontend</b></td>
      <td>
        <img src="https://img.shields.io/badge/React-61DAFB?style=for-the-badge&logo=react&logoColor=black">
        <img src="https://img.shields.io/badge/npm-CB3837?style=for-the-badge&logo=npm&logoColor=white">
        <img src="https://img.shields.io/badge/Vite-646CFF?style=for-the-badge&logo=vite&logoColor=white">
        <img src="https://img.shields.io/badge/ESLint-4B32C3?style=for-the-badge&logo=eslint&logoColor=white">
        <img src="https://img.shields.io/badge/TypeScript-3178C6?style=for-the-badge&logo=typescript&logoColor=white">
        <img src="https://img.shields.io/badge/TailwindCSS-06B6D4?style=for-the-badge&logo=tailwindcss&logoColor=white">
        <img src="https://img.shields.io/badge/Prettier-F7B93E?style=for-the-badge&logo=prettier&logoColor=white">
        <img src="https://img.shields.io/badge/Styled--Components-DB7093?style=for-the-badge&logo=styled-components&logoColor=white">
        <img src="https://img.shields.io/badge/Axios-5A29E4?style=for-the-badge&logo=axios&logoColor=white">
      </td>
    </tr>
    <tr>
      <td><b>Backend</b></td>
      <td>
        <img src="https://img.shields.io/badge/Django-092E20?style=for-the-badge&logo=django&logoColor=white">
        <img src="https://img.shields.io/badge/RabbitMQ-FF6600?style=for-the-badge&logo=rabbitmq&logoColor=white">
        <img src="https://img.shields.io/badge/Celery-37814A?style=for-the-badge&logo=celery&logoColor=white">
        <img src="https://img.shields.io/badge/DRF-ff1709?style=for-the-badge&logo=django&logoColor=white">
        <img src="https://img.shields.io/badge/Django--Channels-34A853?style=for-the-badge&logo=django&logoColor=white">
      </td>
    </tr>
    <tr>
      <td><b>Database</b></td>
      <td>
        <img src="https://img.shields.io/badge/AmazonS3-569A31?style=for-the-badge&logo=amazon-s3&logoColor=white">
        <img src="https://img.shields.io/badge/PostgreSQL-336791?style=for-the-badge&logo=postgresql&logoColor=white">
        <img src="https://img.shields.io/badge/Redis-DC382D?style=for-the-badge&logo=redis&logoColor=white">
        <img src="https://img.shields.io/badge/AmazonRDS-527FFF?style=for-the-badge&logo=amazon-rds&logoColor=white">
      </td>
    </tr>
    <tr>
      <td><b>AI</b></td>
      <td>
        <img src="https://img.shields.io/badge/OpenAI-74aa9c?style=for-the-badge&logo=openai&logoColor=white">
        <img src="https://img.shields.io/badge/DALL·E-1192e8?style=for-the-badge&logo=openai&logoColor=white">
      </td>
      </td>
    </tr>
    <tr>
      <td><b>DevOps</b></td>
      <td>
        <img src="https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white">
        <img src="https://img.shields.io/badge/NGINX-009639?style=for-the-badge&logo=nginx&logoColor=white">
        <img src="https://img.shields.io/badge/AmazonEC2-FF9900?style=for-the-badge&logo=amazon-ec2&logoColor=black">
        <img src="https://img.shields.io/badge/GitHubActions-2088FF?style=for-the-badge&logo=github-actions&logoColor=white">
        <img src="https://img.shields.io/badge/Cloudflare-F38020?style=for-the-badge&logo=cloudflare&logoColor=white">
      </td>
    </tr>
    <tr>
      <td><b>Monitoring</b></td>
      <td>
        <img src="https://img.shields.io/badge/Prometheus-E6522C?style=for-the-badge&logo=prometheus&logoColor=white">
        <img src="https://img.shields.io/badge/Grafana-F46800?style=for-the-badge&logo=grafana&logoColor=white">
        <img src="https://img.shields.io/badge/cAdvisor-0078D7?style=for-the-badge&logo=google&logoColor=white">
        <img src="https://img.shields.io/badge/NodeExporter-00695C?style=for-the-badge&logo=google&logoColor=white">
        <img src="https://img.shields.io/badge/GrafanaLoki-005571?style=for-the-badge&logo=grafana&logoColor=white">
      </td>
    </tr>
    <tr>
      <td><b>ETC</b></td>
      <td>
        <img src="https://img.shields.io/badge/Slack-4A154B?style=for-the-badge&logo=slack&logoColor=white">
        <img src="https://img.shields.io/badge/Notion-000000?style=for-the-badge&logo=notion&logoColor=white">
        <img src="https://img.shields.io/badge/Figma-F24E1E?style=for-the-badge&logo=figma&logoColor=white">
        <img src="https://img.shields.io/badge/Zoom-2D8CFF?style=for-the-badge&logo=zoom&logoColor=white">
        <img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white">
        <img src="https://img.shields.io/badge/Swagger-85EA2D?style=for-the-badge&logo=swagger&logoColor=black">
      </td>
    </tr>
  </table>
</div>


# 📊 Monitoring

<div align="center">
  <h3 align="left">Prometheus & Grafana</h3>
  <table>
        <tr>
            <th colspan="2">Django</th>
        </tr>
        <tr>
            <td><img src="https://github.com/user-attachments/assets/07339efc-48c9-4b9d-b6a1-ea19910eb1db" alt="Django"></td>
            <td><img src="https://github.com/user-attachments/assets/e4099e6f-7463-4b95-af36-f1690b917073" alt="Django2"></td>
        </tr>
        <tr>
            <th colspan="2">Celery</th>
        </tr>
        <tr>
            <td><img src="https://github.com/user-attachments/assets/fa28316e-e970-4135-904c-4ad33acba09d" alt="Celery"></td>
            <td><img src="https://github.com/user-attachments/assets/147d696f-7ff6-40b9-b616-0e28af433d3f" alt="Celery2"></td>
        </tr>
        <tr>
            <th colspan="2">cAdvisor</th>
        </tr>
        <tr>
            <td><img src="https://github.com/user-attachments/assets/b93021b8-a7c5-4943-bcd3-e1d4bd368b1b" alt="cAdvisor"></td>
            <td><img src="https://github.com/user-attachments/assets/fd92cd24-9a2b-49e4-abaf-c58b7612c4b1" alt="cAdvisor2"></td>
        </tr>
        <tr>
            <th colspan="2">Node Exporter</th>
        </tr>
        <tr>
            <td><img src="https://github.com/user-attachments/assets/337fa024-9a4c-4ac3-a6b5-a469d17db4a8" alt="Node Exporter"></td>
            <td><img src="https://github.com/user-attachments/assets/0828286c-a4a5-4fb5-84be-4af5c9fcae90" alt="Node Exporter2"></td>
        </tr>
    </table>
  <br>
  
  <h3 align="left">Cloud Watch</h3>
  <img width="1000" alt="Cloud Watch" src="https://github.com/user-attachments/assets/8d5293c1-ec6e-4743-b3b9-06c44a94c575">
  
  <br>
  
  <h3 align="left">ELK</h3>
  <img width="1000" alt="ELK2" src="https://github.com/user-attachments/assets/3e5d7125-2a92-44d4-bd33-eba6bbd4ac15">
  
</div>

<br>

# 🔧Logging

<div align="center">
   
   |**ELK**|
   |:---------:|
   |<img width="1000" alt="ELK" src="https://github.com/user-attachments/assets/5991a158-203e-471f-b755-2c8de1a86050">|
   
</div>

# 🚀 How To Start

### 1. Clone The Repository
```
https://github.com/2024-Techeer-Summer-Bootcamp-Team-D/MVStudio-Docker.git
```
### 2. ENV Setting In The MVStudio-Docker Folder
* .env
```
ELASTIC_VERSION=
ELASTIC_PASSWORD=
LOGSTASH_INTERNAL_PASSWORD=
KIBANA_SYSTEM_PASSWORD=
METRICBEAT_INTERNAL_PASSWORD=
FILEBEAT_INTERNAL_PASSWORD=
HEARTBEAT_INTERNAL_PASSWORD=
MONITORING_INTERNAL_PASSWORD=
BEATS_SYSTEM_PASSWORD=
INIT_INDEX=
```
* MVStudio-Frontend/.env
```
# 개발 서버 주소
VITE_REACT_APP_BASE_URL =

# 뮤직 비디오 생성 가능 여부
VITE_REACT_APP_IS_OPERATE = true
```
* MVStudio-Backend/.env
```
SECRET_KEY=
DEBUG=

MYSQL_ROOT_PASSWORD=
MYSQL_DATABASE=
MYSQL_USER=
MYSQL_PASSWORD=
DATABASE_HOST=
DB_SQL_MODE=

AWS_ACCESS_KEY_ID=
AWS_SECRET_ACCESS_KEY=
AWS_STORAGE_BUCKET_NAME=
AWS_S3_REGION_NAME=

OPENAI_API_KEY=
SUNO_API_KEY=

SOCIAL_AUTH_GOOGLE_OAUTH2_KEY=
SOCIAL_AUTH_GOOGLE_OAUTH2_SECRET=
RUNWAYML_API_KEY=

BASE_BACKEND_URL=
BASE_FRONTEND_URL=
REFRESH_TOKEN_SECRET=
KAKAO_APP_ADMIN_KEY=
CID=
```
<br>

### 3. Run Docker
```
cd MVStudio-Frontend && npm install && npm run build && cd .. && docker-compose -f docker-compose.prod.yml -f docker-compose.monitoring.yml up -d --build
```
<br>

# 📂 Directory Structure

<details>
    <summary>MVStudio-Docker</summary>
<pre>
<code>

📦MVStudio-Docker
┣ 📂.github
┣ 📂.idea
┣ 📂alertmanager
┣ 📂certbot
┣ 📂elk
┣ 📂grafana
┃ ┗ 📂data
┣ 📂nginx
┃ ┣ 📂app
┃ ┣ 📂logs
┃ ┣ 📜Dockerfile
┃ ┗ 📜nginx.conf
┣ 📂prometheus
┃ ┣ 📜alert-rules.yml
┃ ┗ 📜prometheus.yml
┣ 📂rds_exporter
┃ ┣ 📂basic
┃ ┣ 📂client
┃ ┣ 📂config
┃ ┣ 📂enhanced
┃ ┣ 📂sessions
┃ ┣ 📂tools
┃ ┣ 📜.gitignore
┃ ┣ 📜.golangci-required.yml
┃ ┣ 📜.golangci.yml
┃ ┣ 📜.goreleaser.yml
┃ ┣ 📜CHANGELOG.md
┃ ┣ 📜Dockerfile
┃ ┣ 📜Dockerfile.releaser
┃ ┣ 📜LICENSE
┃ ┣ 📜Makefile
┃ ┣ 📜VERSION
┃ ┣ 📜config.tests.yml
┃ ┣ 📜go.mod
┃ ┣ 📜go.sum
┃ ┗ 📜main.go
┣ 📜.DS_Store
┣ 📜.env
┣ 📜.gitignore
┣ 📜.gitmessage.txt
┣ 📜.gitmodules
┣ 📜README.md
┣ 📜docker-compose-dev.yml
┣ 📜docker-compose-prod.yml
┣ 📜docker-compose.elk.yml
┣ 📜docker-compose.monitoring.yml
┣ 📜docker-compose.prod.yml
┗ 📜init-letsencrypt.sh

</code>
</pre>
</details>

<details>
    <summary>MVStudio-Frontend</summary>
<pre>
<code>

📦MVStudio-Frontend
 ┣ 📂.github
 ┣ 📂.idea
 ┣ 📂dist
 ┣ 📂node_modules
 ┣ 📂src
 ┃ ┣ 📂api
 ┃ ┃ ┣ 📜axios.config.js
 ┃ ┃ ┣ 📜charts.js
 ┃ ┃ ┣ 📜member.js
 ┃ ┃ ┣ 📜musicVideos.js
 ┃ ┃ ┣ 📜onboarding.js
 ┃ ┃ ┣ 📜play.js
 ┃ ┃ ┗ 📜search.js
 ┃ ┣ 📂assets
 ┃ ┃ ┣ 📂font
 ┃ ┃ ┃ ┗ 📜SUIT-Variable.ttf
 ┃ ┃ ┗ 📜image.js
 ┃ ┣ 📂components
 ┃ ┃ ┣ 📂search
 ┃ ┃ ┃ ┗ 📜LongCover.jsx
 ┃ ┃ ┣ 📜BasicTaps.jsx
 ┃ ┃ ┣ 📜GenreSwiper.jsx
 ┃ ┃ ┣ 📜InstSwiper.jsx
 ┃ ┃ ┣ 📜Navbar.jsx
 ┃ ┃ ┣ 📜Service.jsx
 ┃ ┃ ┣ 📜Sidebar.jsx
 ┃ ┃ ┗ 📜StyleSwiper.jsx
 ┃ ┣ 📂libs
 ┃ ┃ ┗ 📂stores
 ┃ ┃ ┃ ┗ 📜userStore.js
 ┃ ┣ 📂pages
 ┃ ┃ ┣ 📂auth
 ┃ ┃ ┃ ┣ 📜Auth.jsx
 ┃ ┃ ┃ ┣ 📜Register.jsx
 ┃ ┃ ┃ ┗ 📜SaveTokens.jsx
 ┃ ┃ ┣ 📂main
 ┃ ┃ ┃ ┣ 📜Header.jsx
 ┃ ┃ ┃ ┣ 📜Main.jsx
 ┃ ┃ ┃ ┗ 📜VideoItem.jsx
 ┃ ┃ ┣ 📂play
 ┃ ┃ ┃ ┣ 📜Play.jsx
 ┃ ┃ ┃ ┗ 📜VideoPlayer.jsx
 ┃ ┃ ┣ 📂user
 ┃ ┃ ┃ ┣ 📜EditProfile.jsx
 ┃ ┃ ┃ ┣ 📜Mypage.jsx
 ┃ ┃ ┃ ┗ 📜YtChannelRegister.jsx
 ┃ ┃ ┣ 📜AppRouter.jsx
 ┃ ┃ ┣ 📜Create.jsx
 ┃ ┃ ┣ 📜LyricsSelect.jsx
 ┃ ┃ ┣ 📜OnBoardingPage.jsx
 ┃ ┃ ┣ 📜Pay.jsx
 ┃ ┃ ┣ 📜Search.jsx
 ┃ ┃ ┣ 📜Upload.jsx
 ┃ ┃ ┣ 📜User.jsx
 ┃ ┃ ┗ 📜ViewChart.jsx
 ┃ ┣ 📂styles
 ┃ ┃ ┣ 📜GlobalStyles.js
 ┃ ┃ ┣ 📜index.css
 ┃ ┃ ┗ 📜swal.config.css
 ┃ ┣ 📂utils
 ┃ ┃ ┣ 📜cookies.js
 ┃ ┃ ┗ 📜igonerePath.js
 ┃ ┣ 📜App.jsx
 ┃ ┗ 📜main.jsx
 ┣ 📜.dockerignore
 ┣ 📜.env
 ┣ 📜.eslintrc.cjs
 ┣ 📜.git
 ┣ 📜.gitignore
 ┣ 📜.gitmessage.txt
 ┣ 📜.prettierrc
 ┣ 📜Dockerfile
 ┣ 📜README.md
 ┣ 📜eslint.config.js
 ┣ 📜index.html
 ┣ 📜jsconfig.json
 ┣ 📜package-lock.json
 ┣ 📜package.json
 ┗ 📜vite.config.js

</code>
</pre>
</details>

<details>
    <summary>MVStudio-Backend</summary>
<pre>
<code>

📦MVStudio-Backend
┣ 📂.github
┣ 📂.idea
┣ 📂charts
┃ ┣ 📂__pycache__
┃ ┣ 📜__init__.py
┃ ┣ 📜admin.py
┃ ┣ 📜apps.py
┃ ┣ 📜models.py
┃ ┣ 📜tests.py
┃ ┣ 📜urls.py
┃ ┗ 📜views.py
┣ 📂config
┃ ┣ 📂__pycache__
┃ ┣ 📜__init__.py
┃ ┣ 📜asgi.py
┃ ┣ 📜celery.py
┃ ┣ 📜settings.py
┃ ┣ 📜urls.py
┃ ┗ 📜wsgi.py
┣ 📂logs
┣ 📂member
┃ ┣ 📂__pycache__
┃ ┣ 📜__init__.py
┃ ┣ 📜admin.py
┃ ┣ 📜apps.py
┃ ┣ 📜callback.py
┃ ┣ 📜constants.py
┃ ┣ 📜models.py
┃ ┣ 📜payment.py
┃ ┣ 📜serializers.py
┃ ┣ 📜tests.py
┃ ┣ 📜urls.py
┃ ┗ 📜views.py
┣ 📂music_videos
┃ ┣ 📂__pycache__
┃ ┣ 📜admin.py
┃ ┣ 📜apps.py
┃ ┣ 📜documents.py
┃ ┣ 📜models.py
┃ ┣ 📜s3_utils.py
┃ ┣ 📜serializers.py
┃ ┣ 📜tasks.py
┃ ┣ 📜tests.py
┃ ┣ 📜urls.py
┃ ┗ 📜views.py
┣ 📂oauth
┃ ┣ 📂__pycache__
┃ ┣ 📜admin.py
┃ ┣ 📜apis.py
┃ ┣ 📜apps.py
┃ ┣ 📜authenticate.py
┃ ┣ 📜handler.py
┃ ┣ 📜mixins.py
┃ ┣ 📜models.py
┃ ┣ 📜services.py
┃ ┣ 📜tests.py
┃ ┣ 📜urls.py
┃ ┣ 📜utils.py
┃ ┗ 📜views.py
┣ 📜.env
┣ 📜.git
┣ 📜.gitignore
┣ 📜.gitmessage.txt
┣ 📜Dockerfile
┣ 📜README.md
┣ 📜manage.py
┗ 📜requirements.txt


</code>
</pre>
</details>
<br>

# 👥 Team Members
<table>
  <tr>
    <th>Name</th>
    <th >조진우</th>
    <th>강기환</th>
    <th>김진희</th>
    <th>박유경</th>
    <th>유성원</th>
    <th>최호원</th>
  </tr>
  <tr>
    <th>Profile</th>
      <td style="text-align:center; vertical-align:middle;"><img src="https://github.com/jinoo0306.png" style="width:100px;height:100px;"></td>
      <td style="text-align:center; vertical-align:middle;"><img src="https://github.com/GiHwan2.png" style="width:100px;height:100px;"></td>
      <td style="text-align:center; vertical-align:middle;"><img src="https://github.com/kimzini.png" style="width:100px;height:100px;"></td>
      <td style="text-align:center; vertical-align:middle;"><img src="https://github.com/ukongee.png" style="width:100px;height:100px;"></td>
      <td style="text-align:center; vertical-align:middle;"><img src="https://github.com/Youth-one.png" style="width:100px;height:100px;"></td>
      <td style="text-align:center; vertical-align:middle;"><img src="https://github.com/BMHowon.png" style="width:100px;height:100px;"></td>
  </tr>
  <tr>
    <th>Role</th>
    <td>Leader, Backend,<br> Frontend, DevOps</td>
    <td>Backend, DevOps</td>
    <td>Backend, DevOps</td>
    <td>Frontend, Design</td>
    <td>Frontend, Design</td>
    <td>Frontend, Design</td>
  </tr>
  <tr>
    <th>GitHub</th>
    <td><a href="https://github.com/jinoo0306">@jinoo0306</a></td>
    <td><a href="https://github.com/Gihwan2">@Gihwan2</a></td>
    <td><a href="https://github.com/kimzini">@kimzini</a></td>
    <td><a href="https://github.com/ukongee">@ukongee</a></td>
    <td><a href="https://github.com/Youth-one">@Youth-one</a></td>
    <td><a href="https://github.com/BMHowon">@BMHowon</a></td>
  </tr>
</table>
<br>
