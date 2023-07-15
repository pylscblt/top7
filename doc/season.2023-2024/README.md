## Creation nouvelle saison
### PDF de la LNR
- Récuperer le calendrier de la nouvelle saison en .pdf sur le site de la LNR

### LibreOffice Calc
- Rentrer les infos dans le fichier .ods
- Save as l'onglet Team en team.csv
- Save as l'onglet Match en match.csv

### Bash scripts
- `./score.sh > score.sql`
- `./match.sh > match.sql`
- `./calendar.sh > calendar.sql`
- `./team.sh > team.sql`

### phpMyAdmin
- table score : Import score.sql
- table match : Import match.sql
- table calendar : Import calendar.sql
- table team : Import team.sql
- table season : Copie last line 
