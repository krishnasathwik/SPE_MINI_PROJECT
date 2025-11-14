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
            echo " Build succeeded — sending success email..."
            emailext(
                subject: "Jenkins Build Successful: ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: """<p>Good news! The build for <b>${env.JOB_NAME} #${env.BUILD_NUMBER}</b> was successful.</p>
                         <p>Check the details here: <a href="${env.BUILD_URL}">${env.BUILD_URL}</a></p>""",
                to: "krishnasathwikmannepalli@gmail.com",
                mimeType: 'text/html'
            )
        }

        failure {
            echo " Build failed — sending failure email..."
            emailext(
                subject: " Jenkins Build Failed: ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: """<p>Oops! The build for <b>${env.JOB_NAME} #${env.BUILD_NUMBER}</b> failed.</p>
                         <p>Check the console output here: <a href="${env.BUILD_URL}">${env.BUILD_URL}</a></p>""",
                to: "krishnasathwikmannepalli@gmail.com",
                mimeType: 'text/html'
            )
        }

        always {
            echo " Email notification stage completed."
        }
    }
}
