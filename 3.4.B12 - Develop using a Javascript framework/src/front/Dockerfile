FROM node:lts-alpine

# make the 'app' folder the current working directory
WORKDIR /front

# copy both 'package.json' and 'package-lock.json' (if available)
# C:\Users\flosh\Desktop\MSC-Pro\PISCINE\P1 - API\T-POO-700-TLS_8\front\package.json
COPY ../package*.json ./

# install project dependencies
RUN yarn install

# copy project files and folders to the current working directory (i.e. 'app' folder)
COPY . .

EXPOSE 8080
CMD [ "yarn", "serve" ]