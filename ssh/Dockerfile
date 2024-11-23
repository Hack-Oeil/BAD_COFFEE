# Utiliser une image de base Debian
FROM debian:latest

# Installer le serveur SSH et d'autres outils nécessaires
RUN apt-get update && apt-get install -y \
    locales \
    openssh-server \
    gcc \
    make \
    sudo \
    libc6-dev-i386 \
    php \
    python3 \
    && rm -rf /var/lib/apt/lists/*

# Créer un utilisateur non-root avec un mot de passe
RUN useradd -m -s /bin/bash -G sudo cyrhades && \
    echo 'cyrhades:secret' | chpasswd

# Générer et configurer les locales en UTF-8
RUN echo "en_US.UTF-8 UTF-8" > /etc/locale.gen && \
    locale-gen en_US.UTF-8

# Définir la locale par défaut
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Définir le répertoire de travail
WORKDIR /home/cyrhades

# Copier les fichiers dans le conteneur
COPY challenge.c .
COPY .passwd .

# Copie le fichier message_ssh.txt depuis le système hôte vers le conteneur
COPY message.txt /etc/motd

# Changer les permissions pour le fichier challenge.c
# Lecture uniquement pour l'utilisateur en cours (cyrhades)
RUN chown cyrhades:cyrhades challenge.c && chmod 400 challenge.c

# Changer les permissions pour le fichier .passwd
# Lecture uniquement pour le propriétaire (root)
RUN chown root:root .passwd && chmod 400 .passwd

# Compiler le fichier C pour créer un binaire challenge
RUN gcc -m32 challenge.c -z noexecstack  -no-pie -fno-stack-protector -o challenge

# Changer les permissions pour le fichier challenge
# Exécution avec les droits du propriétaire et le setuid activé
RUN chown root:cyrhades challenge && chmod 4750 challenge

# Activer le service SSH et préparer l'environnement SSH
RUN mkdir /var/run/sshd

# Configurer le serveur SSH pour permettre la connexion avec le mot de passe
RUN echo "PermitRootLogin no" >> /etc/ssh/sshd_config && \
    echo "PasswordAuthentication yes" >> /etc/ssh/sshd_config && \
    echo "cyrhades ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Exposer le port SSH
EXPOSE 22

# Lancer le serveur SSH
CMD ["/usr/sbin/sshd", "-D"]
