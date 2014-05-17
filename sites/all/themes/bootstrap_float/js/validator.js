(function ($) {

    $(document).ready(function() {
        $('.bv-form').bootstrapValidator({
            message: 'This value is not valid',
            feedbackIcons: {
                valid: 'glyphicon glyphicon-ok',
                invalid: 'glyphicon glyphicon-remove',
                validating: 'glyphicon glyphicon-refresh'
            },
            fields: {
                title: {
                    message: 'The item is not valid',
                    validators: {
                        notEmpty: {
                            message: 'Please enter an item.'
                        },
                        stringLength: {
                            min: 3,
                            max: 255,
                            message: 'Please enter an item.'
                        },
                    }
                },
                email: {
                    validators: {
                        notEmpty: {
                            message: 'The email is required and cannot be empty'
                        },
                        emailAddress: {
                            message: 'The input is not a valid email address'
                        }
                    }
                }
            }
        });
    });

}(jQuery));

