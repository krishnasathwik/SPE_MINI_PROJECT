pipeline {
    agent any

    environment {
        DOCKER_IMAGE = "sathwik049/scientific-calculator:latest"
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main',
                    url: 'https://github.com/krishnasathwik/SPE_MINI_PROJECT.git'
            }
        }

        stage('Build C++') {
            steps {
                sh 'make'
            }
        }

        stage('Run Tests') {
            steps {
                sh 'make test'
            }
        }

        stage('Build Docker Image') {
            steps {
                sh "docker build -t ${DOCKER_IMAGE} ."
            }
        }

        stage('Push Docker Image') {
            steps {
                withDockerRegistry([credentialsId: 'docker-hub-credentials', url: '']) {
                    sh "docker push ${DOCKER_IMAGE}"
                }
            }
        }

        stage('Deploy via Ansible') {
            steps {
                sh 'ansible-playbook -i inventory.ini deploy.yml'
            }
        }
    }
     post {
        success {
            emailext(
                subject: "Jenkins Build Successful: ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: "Good news! The build for ${env.JOB_NAME} #${env.BUILD_NUMBER} was successful.\n\nCheck it here: ${env.BUILD_URL}",
                to: "krishnasathwikmannepalli@gmail.com"
            )
        }
        failure {
            emailext(
                subject: "Jenkins Build Failed: ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: "Oops! The build for ${env.JOB_NAME} #${env.BUILD_NUMBER} failed.\n\nCheck the console output: ${env.BUILD_URL}",
                to: "krishnasathwikmannepalli@gmail.com"
            )
        }
    }
}
