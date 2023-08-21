# ansible-playbooks

RUN tout les playbooks : ansible-playbook -i inventory/inventory.ini main_installation.yml

RUN des playbooks spécifiques : ansible-playbook -i inventory/inventory.ini main_installation.yml --tags nomdutag,nomdutag2

Ne pas oublier de changer les variables d'environnements des fichiers vars si elles sont appelés dans le main_installation.yml

Remplacer les variables d'environnements de inventory.ini

